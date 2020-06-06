#ifndef GROUP_H
#define GROUP_H

#include "Payer.h"
#include "Institution.h"

class Group:
	public Institution
{
private:
	unsigned int group_id;
	Payer group_payer;
	bool isValid;

	void create_group_id();

public:
	Group();
	Group(const std::string& name, const Payer& payer);
	Group(const std::string& name);

	bool isGroup()const;
	Institution* clone()const;

	const std::string getName()const;
	unsigned int getGroupId()const;
	Payer getPayer()const;

	
	bool valid()const;
	bool has_memeber(const Person& p)const;
	Payer* payer()const;

	void print()const;

};
#endif // !GROUP_H

