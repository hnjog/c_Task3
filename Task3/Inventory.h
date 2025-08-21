#pragma once

// 템플릿의 정체는
// 사실 컴파일러가 모든 타입을 검사하고
// 이 클래스를 복붙하여 그 타입마다 만들어주는 방식
// (그래서 Template 함수는 헤더에 선언해야 한다)

#include<iostream>

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
		size = 0;
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
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

	}

	void PrintAllItems() const
	{

	}

	void Assign(const Inventory<T>& other)
	{

	}

	void Resize(int newCapacity)
	{

	}

	void SortItems()
	{

	}

protected:
	T* pItems_;
	int capacity_;
	int size_;
};
