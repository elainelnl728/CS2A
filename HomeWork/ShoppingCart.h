//
//  ShoppingCart.hpp
//  HomeWork
//
//  Created by Elaine on 5/29/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#ifndef ShoppingCart_hpp
#define ShoppingCart_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string cutomerName, string customerName);

    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase itemToPurchase);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase ItemToPurchase);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();
    
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};
#endif /* ShoppingCart_hpp */


