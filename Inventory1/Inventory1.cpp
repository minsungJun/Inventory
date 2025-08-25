// Inventory1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Inven_func.h"
#include "Item_type.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";
    int choice = 0;

    Inventory<Item*> inven(-1);

    cout << inven.GetCapacity() << endl;
    inven.AddItem(new Item("gold", 5000));
    inven.AddItem(new Item("potion", 50));
    inven.AddItem(new Item("feather", 5));
    inven.RemoveLastItem();
    inven.AddItem(new Item("wead", 1));
    inven.SortItems();

    cout << "현재 아이템 개수: " << inven.GetSize() << endl;
    inven.PrintAllItems();
}
