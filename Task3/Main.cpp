#include "pch.h"
#include "Inventory.h"
#include "ItemBase.h"

int main()
{
    Inventory<ItemBase> inven1(15);
    ItemBase item1("Test 무기", 10);
    ItemBase item2("Test 갑옷", 5);
    ItemBase item3("Test 반지", 3);
    ItemBase item4(item3);
    item4.SetName("Test 물약");
    item4.SetPrice(1);

    inven1.AddItem(item1);
    inven1.AddItem(item2);
    inven1.AddItem(item3);
    inven1.AddItem(item4);

    Inventory<ItemBase> inven2(inven1);

    cout << "-----Inven 1 상태-----" << '\n';
    inven1.PrintAllItems();
    
    cout << "-----Inven 1 최신 아이템 제거-----" << '\n';
    inven1.RemoveLastItem();
    inven1.PrintAllItems();

    cout << "-----Inven 2 상태-----" << '\n';
    inven2.PrintAllItems();

    cout << "-----Inven 1에 2를 Assign-----" << '\n';
    inven1.Assign(inven2);
    inven1.PrintAllItems();

    cout << "-----Inven 1 Resize to 20-----" << '\n';
    inven1.Resize(20);
    cout << "Inven 1 용량 : " << inven1.GetCapacity() << '\n';
    cout << "Inven 1 사이즈 : " << inven1.GetSize() << '\n';

    cout << "-----Inven 1 상태-----" << '\n';
    inven1.PrintAllItems();

    cout << "-----Inven 1 아이템들 가격순 오름차순 정렬-----" << '\n';
    inven1.SortItems();
    cout << "-----Inven 1 상태-----" << '\n';
    inven1.PrintAllItems();
}
