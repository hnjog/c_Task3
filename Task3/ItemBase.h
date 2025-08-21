#pragma once

#include<string>

using namespace std;

class ItemBase
{
public:
	ItemBase(string name, int price);
	ItemBase(const ItemBase& other);
	virtual ~ItemBase();

	void PrintInfo() const;

protected:
	string name_;
	int price_;
};