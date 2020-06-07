#ifndef PAYER_H
#define PAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

class Payer
{
private:
	std::string payer_name;
	std::function<bool(int,int)> pred;

public:
	Payer();
	Payer(const std::string& name, std::function<bool(int,int)> pred);

	bool operator==(const Payer& other)const;

	bool payer_member_rule(int group_id, int person_insurance)const;

	const std::string getName()const;

	void print()const;
};
#endif // !PAYER_H
