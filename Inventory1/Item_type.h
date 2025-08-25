#pragma once


using namespace std;

class Item
{
private:
	string name_;
	int price_;
public:
	Item(string name, int price) : name_(name), price_(price) {}

	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}

	int GetPrice() const
	{
		return price_;
	}
};