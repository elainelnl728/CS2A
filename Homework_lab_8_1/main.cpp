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
    string Name1, Name2, Name3, PhoneNum1, PhoneNum2, PhoneNum3;
    
    ContactNode* headObj = nullptr;
    ContactNode* currObj = nullptr;
    ContactNode* lastObj = nullptr;
    
    cout << "Person 1" << endl << "Enter name:" << endl;
    getline(cin, Name1);
    cout << "Enter phone number:" << endl;
    getline(cin, PhoneNum1);
    cout << "You entered: " << Name1 << ", " << PhoneNum1 << endl << endl;
    
    cout << "Person 2" << endl << "Enter name:" << endl;
    getline(cin, Name2);
    cout << "Enter phone number:" << endl;
    getline(cin, PhoneNum2);
    cout << "You entered: " << Name2 << ", " << PhoneNum2 << endl << endl;

    cout << "Person 3" << endl << "Enter name:" << endl;
    getline(cin, Name3);
    cout << "Enter phone number:" << endl;
    getline(cin, PhoneNum3);
    cout << "You entered: " << Name3 << ", " << PhoneNum3 << endl << endl;
    
    headObj = new ContactNode(Name1, PhoneNum1);
    lastObj = headObj;
    
    currObj = new ContactNode(Name2, PhoneNum2);
    lastObj->InsertAfter(currObj);
    lastObj = currObj;
    
    currObj = new ContactNode(Name3, PhoneNum3);
    lastObj->InsertAfter(currObj);
    lastObj = currObj;

    cout << "CONTACT LIST" << endl;
    
    currObj = headObj;
    while (currObj != nullptr) {
        currObj->PrintContactNode();
        cout << endl;
        currObj = currObj->GetNext();
    }
    
    return 0;
}
