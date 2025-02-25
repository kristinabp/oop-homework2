#include "Group.h"

void Group::create_group_id()
{
	this->group_id = group_payer.getName().size()+1000;
}

Group::Group():Institution(), isValid(false)
{
	this->group_id = 0;
}

Group::Group(const std::string & name, const Payer & payer): Institution(name, payer), group_payer(Payer(payer))
{
	create_group_id();
	this->isValid = true;
}

Group::Group(const std::string & name): Institution(name), group_payer(Payer()), isValid(false)
{
	this->group_id = 0;
}

bool Group::isGroup() const
{
	return true;
}

Institution * Group::clone() const
{
	return new Group(*this);
}

const std::string Group::getName() const
{
	return this->institution_name;
}

unsigned int Group::getGroupId() const
{
	return this->group_id;
}

const std::string Group::getInstitutionId() const
{
	return this->institution_id;
}

Payer Group::getPayer() const
{
	return this->group_payer;
}

bool Group::valid() const
{
	return this->isValid;
}

bool Group::has_memeber(const Person & p) const
{
	if (this->group_payer.payer_member_rule(this->group_id, p.getId())) //if there is no payer the payer_member_rule returns false, because no payer exists
	{
		//std::cout << "This person is part from the group " << this->institution_name << "\n";
		return true;
	}
	else
	{
		//std::cout << "This person is not part from the group " << this->institution_name << "\n";
		return false;
	}
}

Payer * Group::payer() const
{
	if (this->group_payer.getName() != "no payer")
	{
		return new Payer(this->group_payer);
	}
	else
	{
		return nullptr;
	}
}

void Group::print() const
{
	std::cout << this->institution_name << ' ' << this->group_id << "\n";
}
