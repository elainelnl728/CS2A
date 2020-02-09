//
//  main(lab 7.21).cpp
//  HomeWork
//
//  Created by Elaine on 5/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include <stdio.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

#include <string>
#include <iostream>
using namespace std;

void PrintMenu(ShoppingCart shoppingCart) {
    char option = '\0';
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
    
    const string menu = "MENU\na - Add item to cart\nd - Remove item from cart\nc - Change item quantity\ni - Output items' descriptions\no - Output shopping cart\nq - Quit\n";
    cout << menu << endl;
    
    while (true) {
        cout << "Choose an option:" << endl;
        cin >> option;

        switch (option) {
            case 'q':
                return;
            case 'a': {
                ItemToPurchase itemToPurchase;
                cout << "ADD ITEM TO CART\nEnter the item name:" << endl;
                cin.ignore();
                getline(cin, itemName);
                itemToPurchase.SetName(itemName);
                cout << "Enter the item description:" << endl;
                getline(cin, itemDescription);
                itemToPurchase.SetDescription(itemDescription);
                cout << "Enter the item price:" << endl;
                cin >> itemPrice;
                itemToPurchase.SetPrice(itemPrice);
                cout << "Enter the item quantity:" << endl;
                cin >> itemQuantity;
                itemToPurchase.SetQuantity(itemQuantity);
                shoppingCart.AddItem(itemToPurchase);
                cout << endl;
                
                cout << menu << endl;
                break;
            }
            case 'd': {
                cout << "REMOVE ITEM FROM CART\nEnter name of item to remove:" << endl;
                cin.ignore();
                getline(cin, itemName);
                shoppingCart.RemoveItem(itemName);
                cout << endl;
                
                cout << menu << endl;
                break;
            }
            case 'c': {
                cout << "CHANGE ITEM QUANTITY\nEnter the item name:" << endl;
                ItemToPurchase itemToPurchase;
                cin.ignore();
                getline(cin, itemName);
                itemToPurchase.SetName(itemName);
                cout << "Enter the new quantity:" << endl;
                cin >> itemQuantity;
                itemToPurchase.SetQuantity(itemQuantity);
                shoppingCart.ModifyItem(itemToPurchase);
                cout << endl;
                
                cout << menu << endl;
                break;
            }
            case 'i': {
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                shoppingCart.PrintDescriptions();
                cout << endl;
                
                cout << menu << endl;
                break;
            }
            case 'o': {
                cout << "OUTPUT SHOPPING CART" << endl;
                shoppingCart.PrintTotal();
                cout << endl;
                
                cout << menu << endl;
                break;
            }
        }
    }
}

int main2(int argc, const char * argv[]) {
    string customerName;
    string currentDate;
    
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    
    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    cout << endl;
    
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl << endl;
    
    ShoppingCart shoppingCartToday(customerName, currentDate);
    PrintMenu(shoppingCartToday);
    
    return 0;
}
