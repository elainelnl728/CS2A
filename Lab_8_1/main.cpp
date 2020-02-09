//
//  main.cpp
//  HomeWork
//
//  Created by Elaine on 6/9/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "ContactNode.h"

int main(int argc, const char * argv[]) {
    string Name1, Name2 Name3, PhoneNum1, PhoneNum2, PhoneNume3;
    
    ContactNode* headObj = nullptr;
    ContactNode* currObj = nullptr;
    ContactNode* lastObj = nullptr;
    
    cout << "Person 1" << endl << "Enter Name:" << endl;
    getline(cin, Name1);
    cout << "Enter phone number" << endl;
    getline(cin, PhoneNum1);
    
    cout << "Person 2" << endl << "Enter Name:" << endl;
    etline(cin, Name2);
    cout << "Enter phone number" << endl;
    getline(cin, PhoneNum2);
    
    cout << "Person 3" << endl << "Enter Name:" << endl;
    etline(cin, Name3);
    cout << "Enter phone number" << endl;
    getline(cin, PhoneNum3);
    
    headObj = new ContactNode(name1, PhoneNum1);
    lastObj = headObj;
    
    currentObj = new ContactNode(name2, PhoneNum3);
    lastObj->InsertAfter(currObj);
    
    currObj = headObj;
    while (currObj != nullptr) {
        currObj->PrintContactNode();
        currObj = currObj->GetNext();
    }
    
    return 0;
}
