//
//  ItemToPurchase.hpp
//  HomeWork
//
//  Created by Elaine on 5/26/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#ifndef ItemToPurchase_hpp
#define ItemToPurchase_hpp

#include <stdio.h>
#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity = 0);

    void SetName(string itemName);
    string GetName();
    void SetPrice(int itemPrice);
    int GetPrice();
    void SetQuantity(int itemQuantity);
    int GetQuantity();
    void SetDescription(string itemDescription);
    string GetDescription();
    void PrintItemCost();
    void PrintItemDescription();
    
private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif /* ItemToPurchase_hpp */
