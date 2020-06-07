#include "Person.h"
#include <iostream>
#include "Group.h"
#include "Organization.h"


void find_most_popular_institution(std::vector<Institution*> i, std::vector<Person*> users)
{
	std::vector<int> popularity;
	for (size_t k = 0; k < i.size(); k++)
	{
		popularity.push_back(0);
	}

	for (size_t k = 0; k < users.size(); k++)
	{
		for (size_t j = 0; j < i.size(); j++)
		{
			if (i[j]->has_memeber(*users[k]))
			{
				popularity[j]++;
			}
		}
	}

	int max = 0;
	int curIndex = 0;
	for (size_t k = 0; k < popularity.size(); k++)
	{
		if (max < popularity[k])
		{
			max = popularity[k];
			curIndex = k;
		}
	}

	if (popularity[curIndex] != 0)
	{
		std::cout << i[curIndex]->getName();
	}
	else
	{
		std::cout << "No users are associated. \n";
	}
}

std::vector<Institution*> clear_institutions(std::vector<Institution*> inst)
{
	std::vector<Institution*> newList;
	for (size_t i = 0; i < inst.size(); i++)
	{
		if (inst[i]->valid())
		{
			newList.push_back(inst[i]);
		}
	}

	return newList;
}

int main()
{
	Payer p1("Bulstrad", [](int x, int y) {return x == y; });
	Payer p2("Alianz", [](int x, int y) {return x == y; });
	Group g1("G1");
	Group g2("G2", p1);
	Group g4("G4", p2);
	Group g3("G3");
	Organization o1("O1",{ &g2, &g3 }, "Unknown adress");
	Organization o2("O2",{&o1},"Another adress");
	Person per1("John Smith", p1);
	Person per2("Jane Smith", p1);
	Person per3("Erica Smith", p1);
	Person per4("Erica Smith");

	/*std::vector<Institution*> ins = clear_institutions({ &g2, &g4, &o1, &o2 });
	for (size_t i = 0; i < ins.size(); i++)
	{
		std::cout << ins[i]->getName() << '\n';
	}*/

	//find_most_popular_institution({ &o1, &o2, &g2, &g4 }, { &per1, &per2, &per3 });
	
	//o1.has_memeber(per2);
	return system("pause");
}