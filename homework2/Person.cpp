#include "Person.h"

void Person::copy(const Person & other)
{
	this->person_name = other.person_name;
	this->insurance_id = other.insurance_id;
	this->hasInsurance = other.hasInsurance;
	this->person_payer = other.person_payer;
}

Person::Person(): person_payer(Payer())
{
	this->person_name = "";
	this->hasInsurance = false;
	this->insurance_id = 0;
}

Person::Person(const std::string& name, const Payer& payer) :person_name(name), person_payer(Payer(payer))
{
	this->hasInsurance = true;
	this->insurance_id = payer.getName().size()+1000;
}

Person::Person(const std::string & name):person_name(name), person_payer(Payer())
{
	this->hasInsurance = false;
	this->insurance_id = 0;
}

Person::Person(const Person& other)
{
	copy(other);
}

Person::~Person()
{
}

const std::string Person::getName() const
{
	return this->person_name;
}

int Person::getId() const
{
	return this->insurance_id;
}

Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

void Person::print() const
{
	std::cout << person_name << ' ' << insurance_id << '\n';
}

