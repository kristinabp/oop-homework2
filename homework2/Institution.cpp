#include "Institution.h"

int Institution::count_institutions = 0;

void Institution::copy(const Institution & other)
{
	this->institution_name = other.institution_name;
	this->institution_id =other.institution_id;
}

void Institution::createId()
{
	this->institution_id =std::to_string(this->count_institutions)+"-"+this->institution_name;
}

Institution::Institution(): institution_payer(Payer())
{
	this->institution_name = "";
	createId();
}

Institution::Institution(const std::string& name)
{
	this->institution_name = name;
	this->count_institutions++;
	createId();
}

Institution::Institution(const Institution & other)
{
	copy(other);
}

Institution & Institution::operator=(const Institution & other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

const std::string Institution::getName() const
{
	return this->institution_name;
}

const std::string Institution::getId() const
{
	return this->institution_id;
}

Payer Institution::getPayer() const
{
	return this->institution_payer;
}

void Institution::print() const
{
	std::cout << this->institution_name << ' ';
	this->institution_payer.print();
	std::cout << ' ' << this->institution_id << '\n';
}
