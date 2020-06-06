#include "Organization.h"

void Organization::findPayer()
{
	if (institutions_list.empty())
	{
		this->organization_payer = Payer();
		return;
	}

	std::vector<std::string> groupPayerNames;
	for (size_t i = 0; i < institutions_list.size(); i++)
	{
		if (institutions_list[i]->isGroup())
		{
			groupPayerNames.push_back(institutions_list[i]->getPayer().getName());
		}
	}

	//using Boyer–Moore majority vote algorithm to find the most common payer
	std::string payer = "";
	int counter = 0;
	for (size_t i = 0; i < groupPayerNames.size(); i++)
	{
		if (counter == 0)
		{
			payer = groupPayerNames[i];
			counter = 1;
		}
		else if (payer == groupPayerNames[i])
		{
			counter++;
		}
		else
		{
			counter--;
		}
	}

	this->organization_payer = Payer(payer, [](int x, int y) {return x == y; });
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

Organization::Organization():institutions_list(std::vector<Institution*>()), organization_adress(""), organization_payer(Payer())
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
	return this->organization_payer;
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
				return true;
			}
		}
		else if(!institutions_list[i]->isGroup())
		{
			/*if ()
			{
				return true;
			}*/
		}
		
	}

	return false;
}

Payer * Organization::payer() const
{
	if (this->organization_payer.getName() != "no payer")
	{
		return new Payer(this->organization_payer);
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
		if (!i->isGroup() && checkOrganizations(i) && i->valid()) // ако не е група, трябва да е съвместима и валидна
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

