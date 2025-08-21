#include "pch.h"
#include "ItemBase.h"

ItemBase::ItemBase(string name, int price)
	:name_(name),
	price_(price)
{
}

ItemBase::ItemBase(const ItemBase& other)
{
	name_ = other.name_;
	price_ = other.price_;
}

ItemBase::~ItemBase()
{
	name_.clear();
}

void ItemBase::PrintInfo() const
{
	cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << '\n';
}