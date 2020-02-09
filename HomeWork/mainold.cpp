//
//  main.cpp
//  HomeWork
//
//  Created by Elaine on 5/26/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "ItemToPurchase.h"

#include <string>
#include <iostream>
using namespace std;

int main0(int argc, const char * argv[]) {
    ItemToPurchase item1;
    string itemName;
    cout << "Item 1\nEnter the item name:\n";
    getline(cin, itemName);
    item1.SetName(itemName);
    
    int itemPrice;
    cout << "Enter the item price:\n";
    cin >> itemPrice;
    item1.SetPrice(itemPrice);
    
    int itemQuantity;
    cout << "Enter the item quantity:\n";
    cin >> itemQuantity;
    item1.SetQuantity(itemQuantity);
    
    cin.ignore();
    
    ItemToPurchase item2;
    cout << "\nItem 2\nEnter the item name:\n";
    getline(cin, itemName);
    item2.SetName(itemName);
    
    cout << "Enter the item price:\n";
    cin >> itemPrice;
    item2.SetPrice(itemPrice);
    
    cout << "Enter the item quantity:\n";
    cin >> itemQuantity;
    item2.SetQuantity(itemQuantity);
    
    int totalCost = 0, item1Cost = 0, item2Cost = 0;
    item1Cost = item1.GetPrice() * item1.GetQuantity();
    item2Cost = item2.GetPrice() * item2.GetQuantity();
    totalCost = item1Cost + item2Cost;
    
    cout << "\nTOTAL COST\n";
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1Cost << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2Cost << endl << endl;
    cout << "Total: $" << totalCost << endl;
    
    return 0;
}
