#include "Organization.h"

void Organization::findPayer()
{
	if (institutions_list.empty())
	{
		this->institution_payer = Payer();
		return;
	}

	std::vector<Payer> groupPayers; // "застраховател на организацията е този с най-много пряко асоциирани групи"
	for (size_t i = 0; i < institutions_list.size(); i++) // добавяме само групите на първо ниво в йерархията
	{                                  // ако такива няма долният алгоритъм няма да се изпълни
		if (institutions_list[i]->isGroup())
		{
			groupPayers.push_back(institutions_list[i]->getPayer());
		}
	}
	
	//using Boyer–Moore majority vote algorithm to find the most common payer
	Payer payer;
	int counter = 0;
	
	for (size_t i = 0; i < groupPayers.size(); i++)
	{
		if (counter == 0)
		{
			payer = groupPayers[i];
			counter = 1;
		}
		else if (payer == groupPayers[i])
		{
			counter++;
		}
		else
		{
			counter--;
		}
	}
	this->institution_payer = payer;
}

bool Organization::findGroup()
{
	for (size_t i = 0; i < institutions_list.size(); i++)
	{
		if (institutions_list[i]->isGroup())
		{
			return true;
		}
	}
	return false;
}

bool Organization::checkOrganizations(Institution* o)
{
	for (size_t i = 0; i < institutions_list.size(); i++)
	{
		if (institutions_list[i]->getPayer().getName() == o->getPayer().getName())
		{
			return true;
		}
	}
	return false;
}

Organization::Organization():Institution(), institutions_list(std::vector<Institution*>()), organization_adress("")
{
	this->isValid = false;
}

Organization::Organization(const std::string& name,std::vector<Institution*> list, const std::string & adress):Institution(name),
organization_adress(adress)
{
	this->institutions_list = list;
	findPayer();
	this->isValid=findGroup();
}

bool Organization::isGroup() const
{
	return false;
}

const std::string Organization::getName() const
{
	return this->institution_name;
}

Payer Organization::getPayer() const
{
	return this->institution_payer;
}

const std::string Organization::getInstitutionId() const
{
	return this->institution_id;
}

std::vector<Institution*> Organization::getInstitutions() const
{
	return this->institutions_list;
}

bool Organization::valid() const
{
	return this->isValid;
}

bool Organization::has_memeber(const Person & p) const
{
	for (size_t i = 0; i < institutions_list.size(); i++)
	{
		if (institutions_list[i]->isGroup())
		{
			if (institutions_list[i]->has_memeber(p))
			{
				//std::cout << "This person is part from the organization " << this->institution_name << "\n";
				return true;
			}
		}
		else if(!institutions_list[i]->isGroup())
		{
			if (institutions_list[i]->has_memeber(p))
			{
				//std::cout << "This person is part from the organization " << this->institution_name << "\n";
				return true;
			}
		}
		
	}
	//std::cout << "This person is not part from the organization " << this->institution_name << "\n";
	return false;
}

Payer * Organization::payer() const
{
	if (this->institution_payer.getName() != "no payer")
	{
		return new Payer(this->institution_payer);
	}
	else
	{
		return nullptr;
	}
}

void Organization::add_institution(Institution* i, bool ruleAdded)
{
	if (ruleAdded)
	{
		if (!i->isGroup() && checkOrganizations(i) && i->valid()) // ако не е група е организация и тя трябва да е съвместима и валидна
		{
			institutions_list.push_back(i->clone());
		}
		else if (i->valid()) // ако е група, проверяваме дали е валидна
		{
			institutions_list.push_back(i->clone());
		}
	}
	else
	{
		institutions_list.push_back(i->clone());
	}
}

Institution * Organization::clone() const
{
	return new Organization(*this);
}

