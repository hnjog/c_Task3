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

	// Setter
	void SetName(string&& name) { name_ = move(name); }
	void SetPrice(int price) { price_ = price; }

	// Getter
	const string& GetName() { return name_; }
	int GetPrice() { return price_; }

protected:
	string name_;
	int price_;
};

// printinfo 말고 여기에
// ostream << 관련 연산자 오버로딩을 하는 방법도 존재
// 다만 그때는 printinfo 를 안 만들어도 되기에
// 그냥 template 명시화를 이용한다