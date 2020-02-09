//
//  ItemToPurchase.cpp
//  HomeWork
//
//  Created by Elaine on 5/26/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "ItemToPurchase.h"

#include <iostream>
#include <string>

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity) {
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->itemPrice = itemPrice;
    this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string itemName) {
    this->itemName = itemName;
}

string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(int itemPrice) {
    this->itemPrice = itemPrice;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
    this->itemQuantity = itemQuantity;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription) {
    this->itemDescription = itemDescription;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}

