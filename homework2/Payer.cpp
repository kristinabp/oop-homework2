#include "Payer.h"

Payer::Payer(): payer_name("no payer"), pred(std::function<bool(int, int)>())
{
}

Payer::Payer(const std::string & name, std::function<bool(int, int)> pred):payer_name(name), pred(pred)
{
}

bool Payer::payer_member_rule(int group_id, int person_insurance)
{
	return pred(group_id, person_insurance);
}


const std::string Payer::getName() const
{
	return this->payer_name;
}

void Payer::print() const
{
	std::cout << this->payer_name << ' ';
}
