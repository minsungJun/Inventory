#pragma once
#include <iostream>
#include <algorithm>
#include "Item_type.h"

using namespace std;

template <typename T>
class Inventory
{
private:
	T* pItems_;		//아이템 객체들을 저장할 동적 배열을 가리키는 포인터입니다. new T[]를 통해 메모리를 할당받습니다.
	int size_;		//인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
	int capacity_;	//현재 인벤토리에 저장된 아이템의 실제 개수입니다.

public:
	Inventory(int capacity = 10) : capacity_(capacity)
	{
		if (capacity < 0)capacity_ = 1;
		size_ = 0;
		pItems_ = new T[capacity_];
	}

	Inventory(const Inventory<T>& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	}

	~Inventory()
	{
		for (int i = 0; i < size_; i++)
		{
			delete pItems_[i];        // pItems_[i] 는 Item*
		}
		delete[] pItems_;
		pItems_ = nullptr;
	}


	void AddItem(const T& item)
	{
		// 새로운 아이템을 인벤토리에 추가합니다.
		// `size_`가 `capacity_`보다 작을 경우에만 아이템을 추가하고, `size_`를 1 증가시킵니다.
		// 인벤토리가 꽉 찼다면 "인벤토리가 꽉 찼습니다!" 메시지를 출력하고 아무 동작도 하지 않습니다.
		if (size_ < capacity_)
		{
			pItems_[size_] = item;
			size_++;
		}
		else
		{
			SizeUpArr(pItems_);
			capacity_ *= 2;
			pItems_[size_] = item;
			size_++;
			cout << "인벤토리를 늘렸습니다" << endl;
		}
	}
	void RemoveLastItem()
	{
		// 인벤토리의 가장 마지막에 추가된 아이템을 제거합니다.
		// 실제로 메모리를 지우는 것이 아니라, 아이템의 개수를 나타내는 `size_`를 1 감소시켜 마지막 아이템에 접근할 수 없도록 만듭니다.
		// 인벤토리가 비어있다면 "인벤토리가 비어있습니다." 메시지를 출력합니다.
		if (size_ > 0)size_--;
		else cout << "인벤토리가 비어있습니다" << endl;

	}
	int GetSize() const
	{
		// 현재 인벤토리에 저장된 아이템의 개수(size_)를 반환합니다.
		return size_;
	}
	int GetCapacity() const
	{
		// 인벤토리의 최대 저장 용량(capacity_)을 반환합니다.
		return capacity_;
	}
	void PrintAllItems() const
	{
		// 인벤토리에 있는 모든 아이템의 정보를 화면에 출력합니다.
		// `for` 반복문을 이용해 `0`번 인덱스부터 `size_ - 1`번 인덱스까지 순회하며, 각 아이템 객체의 `PrintInfo()` 멤버 함수를 호출합니다.
		// 만약 인벤토리가 비어있다면 "(비어있음)" 메시지를 출력합니다.
		for (int i = 0; i < size_; i++)
		{
			pItems_[i]->PrintInfo();
		}
	}
	void Resize(int newCapacity)
	{
		capacity_ = newCapacity;
	}

	void SortItems() 
	{
		std::sort(pItems_, pItems_ + size_,[](Item* a, Item* b) 
			{
				return a->GetPrice() < b->GetPrice();
			}
		);
	}

	void SizeUpArr(T*& arr) {
		T* temp = new T[capacity_ * 2];
		copy(arr, arr + size_, temp);
		delete[](arr);
		arr = temp;
		temp = NULL;
	}

};