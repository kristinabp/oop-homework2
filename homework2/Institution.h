#ifndef INSTITUTION_H
#define INSTITUTION_H

#include <cstring>
#include <string>
#include <iostream>
#include "Person.h"
#include "Payer.h"

class Institution
{
protected:
	std::string institution_name;
	std::string institution_id;
	static int count_institutions;
	Payer institution_payer;

	void copy(const Institution& other);

	void createId();

public:
	Institution();
	Institution(const std::string& name, const Payer& payer);
	Institution(const std::string& name);
	Institution(const Institution& other);

	Institution& operator=(const Institution& other);

	virtual const std::string getName()const = 0;
	virtual const std::string getInstitutionId()const = 0;
	virtual Payer getPayer()const = 0;

	virtual bool isGroup() const = 0;
	virtual Institution* clone()const = 0;

	virtual bool has_memeber(const Person& p)const = 0;
	virtual Payer* payer()const = 0;
	virtual bool valid()const = 0;

};
#endif // !INSTITUTION_H
