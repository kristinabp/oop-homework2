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
	this->count_institutions++;
	createId();
}

Institution::Institution(const std::string & name, const Payer & payer): institution_name(name), institution_payer(payer)
{
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