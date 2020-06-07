#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <vector>
#include "Institution.h"

class Organization:
	public Institution
{
private:
	std::vector<Institution*> institutions_list;
	std::string organization_adress;
	bool isValid;

	void findPayer();
	bool findGroup();
	bool checkOrganizations(Institution* o);

public:
	Organization();
	Organization(const std::string& name, std::vector <Institution*> list, const std::string& adress);

	bool isGroup()const;

	const std::string getName()const;
	Payer getPayer()const;
	const std::string getInstitutionId() const;
	std::vector <Institution*> getInstitutions()const;

	bool valid()const;
	bool has_memeber(const Person& p)const;
	Payer* payer()const;

	void add_institution(Institution* i, bool ruleAdded=true);
	Institution* clone()const;

};
#endif // !ORGANIZATION_H

