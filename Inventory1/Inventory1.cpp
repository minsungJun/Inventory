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
    string name = "";
    int price = 0;

    cout << "인벤토리의 크기를 결정하세요" << endl;
    cin >> choice;
    Inventory<Item*> inven(choice);
    cout << "인벤토리의 크기 : " << inven.GetCapacity() << endl;
    while (choice != 5)
    {
        cout << "번호를 입력하세요" << endl;
        cout << "1. 아이템 추가 2. 아이템 제거 3. 아이템 출력 4. 인벤토리 정렬 5. 종료" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "아이템의 이름과 가격을 입력하세요" << endl;
            cin >> name;
            cin >> price;
            inven.AddItem(new Item(name, price));
            cout << "현재 아이템 개수: " << inven.GetSize() << endl;
            break;
        case 2:
            cout << "마지막 아이템을 제거합니다" << endl;
            inven.RemoveLastItem();
            cout << "현재 아이템 개수: " << inven.GetSize() << endl;
            break;
        case 3:
            inven.PrintAllItems();
            break;
        case 4:
            cout << "인벤토리를 정렬합니다" << endl;
            inven.SortItems();
            break;
        case 5:
            cout << "종료합니다" << endl;
            break;
        default:
            
            break;
        }

    }



}
