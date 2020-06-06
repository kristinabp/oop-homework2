#ifndef PERSON_H
#define PERSON_H

#include <cstring>
#include <iostream>
#include <string>
#include "Payer.h"

class Person
{
private:
	std::string person_name;
	int insurance_id;
	bool hasInsurance;
	Payer person_payer;

	void copy(const Person& other);

public:
	Person();
	Person(const std::string& name, const Payer& payer);
	Person(const std::string& name);
	Person(const Person& other);
	~Person();

	const std::string getName()const;
	int getId()const;

	Person& operator=(const Person& other);

	void print()const;
};
#endif // !PERSON_H
