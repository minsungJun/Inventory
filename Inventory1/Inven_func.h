#pragma once
#include <iostream>
#include <algorithm>
#include "Item_type.h"

using namespace std;

template <typename T>
class Inventory
{
private:
	T* pItems_;		//������ ��ü���� ������ ���� �迭�� ����Ű�� �������Դϴ�. new T[]�� ���� �޸𸮸� �Ҵ�޽��ϴ�.
	int size_;		//�κ��丮�� �ִ�� ������ �� �ִ� ������ ũ���Դϴ�.
	int capacity_;	//���� �κ��丮�� ����� �������� ���� �����Դϴ�.

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
		cout << "�κ��丮 ���� �Ϸ�" << endl;
	}

	~Inventory()
	{
		for (int i = 0; i < size_; i++)
		{
			delete pItems_[i];        // pItems_[i] �� Item*
		}
		delete[] pItems_;
		pItems_ = nullptr;
	}


	void AddItem(const T& item)
	{
		// ���ο� �������� �κ��丮�� �߰��մϴ�.
		// `size_`�� `capacity_`���� ���� ��쿡�� �������� �߰��ϰ�, `size_`�� 1 ������ŵ�ϴ�.
		// �κ��丮�� �� á�ٸ� "�κ��丮�� �� á���ϴ�!" �޽����� ����ϰ� �ƹ� ���۵� ���� �ʽ��ϴ�.
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
			cout << "�κ��丮�� �÷Ƚ��ϴ�" << endl;
		}
	}
	void RemoveLastItem()
	{
		// �κ��丮�� ���� �������� �߰��� �������� �����մϴ�.
		// ������ �޸𸮸� ����� ���� �ƴ϶�, �������� ������ ��Ÿ���� `size_`�� 1 ���ҽ��� ������ �����ۿ� ������ �� ������ ����ϴ�.
		// �κ��丮�� ����ִٸ� "�κ��丮�� ����ֽ��ϴ�." �޽����� ����մϴ�.
		if (size_ > 0)size_--;
		else cout << "�κ��丮�� ����ֽ��ϴ�" << endl;

	}
	int GetSize() const
	{
		// ���� �κ��丮�� ����� �������� ����(size_)�� ��ȯ�մϴ�.
		return size_;
	}
	int GetCapacity() const
	{
		// �κ��丮�� �ִ� ���� �뷮(capacity_)�� ��ȯ�մϴ�.
		return capacity_;
	}
	void PrintAllItems() const
	{
		// �κ��丮�� �ִ� ��� �������� ������ ȭ�鿡 ����մϴ�.
		// `for` �ݺ����� �̿��� `0`�� �ε������� `size_ - 1`�� �ε������� ��ȸ�ϸ�, �� ������ ��ü�� `PrintInfo()` ��� �Լ��� ȣ���մϴ�.
		// ���� �κ��丮�� ����ִٸ� "(�������)" �޽����� ����մϴ�.
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