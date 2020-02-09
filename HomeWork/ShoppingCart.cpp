//
//  ShoppingCart.cpp
//  HomeWork
//
//  Created by Elaine on 5/29/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "ShoppingCart.h"

#include <iostream>
#include <string>
#include <vector>

#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
    this->customerName = customerName;
    this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase itemToPurchase) {
    cartItems.push_back(itemToPurchase);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool is_found = false;
    for(auto iter = cartItems.begin(); iter != cartItems.end(); iter++) {
        if(iter->GetName() == itemName) {
            cartItems.erase(iter);
            is_found = true;
            break;
        }
    }
    if (!is_found) {
        cout << "Item not found in cart. Nothing removed." << endl;
        
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase ItemToPurchase) {
    auto iter = cartItems.begin();
    for(; iter != cartItems.end(); iter++) {
        if(iter->GetName() == ItemToPurchase.GetName()) {
            if (ItemToPurchase.GetDescription() != "none") {
                iter->SetDescription(ItemToPurchase.GetDescription());
            }
            if (ItemToPurchase.GetPrice() != 0) {
                iter->SetPrice(ItemToPurchase.GetPrice());
            }
            if (ItemToPurchase.GetQuantity() != 0) {
                iter->SetQuantity(ItemToPurchase.GetQuantity());
            }
            break;
        }
    }
    if (iter == cartItems.end()) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int totalQuantity = 0;
    for(auto iter = cartItems.begin(); iter != cartItems.end(); iter++) {
        totalQuantity += iter->GetQuantity();
    }
    return totalQuantity;
}

int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    for(auto iter = cartItems.begin(); iter != cartItems.end(); iter++) {
        totalCost += (iter->GetQuantity() * iter->GetPrice());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
    
    auto iter = cartItems.begin();
    for(; iter != cartItems.end(); iter++) {
        iter->PrintItemCost();
    }
    
    if(cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl;
    
    cout << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    auto iter = cartItems.begin();
    for(; iter != cartItems.end(); iter++) {
        iter->PrintItemDescription();
    }
}

