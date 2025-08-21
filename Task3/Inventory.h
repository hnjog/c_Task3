#pragma once

// 템플릿의 정체는
// 사실 컴파일러가 모든 타입을 검사하고
// 이 클래스를 복붙하여 그 타입마다 만들어주는 방식
// (그래서 Template 함수는 헤더에 선언해야 한다)

#include<iostream>
#include"ItemBase.h"

using namespace std;

template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10)
	{
		if (capacity < 0)
			capacity = 1;

		pItems_ = new T[capacity];
		capacity_ = capacity;
		size_ = 0;
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other)
	{
		Assign(other);

		cout << "인벤토리 복사 완료" << '\n';
	}

	virtual ~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

public:
	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}

		pItems_[size_] = item;
		size_++;
	}

	// Getter
	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }

	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			cout << "인벤토리가 비어있습니다." << '\n';
		}

		size_--;
	}

	void PrintAllItems() const;

	void Assign(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) 
		{
			pItems_[i] = other.pItems_[i];
		}
	}

	void Resize(int newCapacity)
	{
		// 더 작은 용량이나 같은 용량으로 resize 하지 않는다
		if (newCapacity <= capacity_)
			return;

		T* originItems = pItems_;
		capacity_ = newCapacity;
		pItems_ = new T[capacity_];
		
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = originItems[i];
		}

		delete[] originItems;
	}

	void SortItems();

protected:
	T* pItems_;
	int capacity_;
	int size_;
};

// 기본 템플릿 구현은 비어 있도록
template <typename T>
void Inventory<T>::PrintAllItems() const 
{
	cout << "뭘 기대하신 거죠?" << '\n';
}

// 기본 템플릿 구현은 비어 있도록
template <typename T>
void Inventory<T>::SortItems()
{
	cout << "뭘 기대하신 거죠?" << '\n';
}

// ItemBase 일때만 사용 가능한 명시적 특수화
template<>
inline void Inventory<ItemBase>::PrintAllItems() const
{
	for (int i = 0; i < size_; i++)
	{
		pItems_[i].PrintInfo();
	}
}

// ItemBase 일때만 사용 가능한 명시적 특수화
template<>
inline void Inventory<ItemBase>::SortItems()
{
	sort(pItems_, pItems_ + size_, [](const ItemBase& a, const ItemBase& b)
		{
			return a.GetPrice() < b.GetPrice();
		});
}