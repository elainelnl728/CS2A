//
//  ContactNode.cpp
//  HomeWork
//
//  Created by Elaine on 6/9/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "ContactNode.h"
#include <iostream>
#include <string>

ContactNode::ContactNode(string name, string PhoneNum) {
    this->contactName = name;
    this->contactPhoneNum = PhoneNum;
}

ContactNode::GetName() {
    return this->contactName;
}

ContactNode::GetPhoneNumber() {
    return this->contactPhoneNum;
}

ContactNode* ContactNode::GetNext() {
    return this->nextNodePtr;
}
void ContactNode::PrintContactNode() {
    cout << "Name: " << this->contactName;
    cout << "Phone number" << this->contactPhoneNum;
}

void ContactNode::InsertAfter(ContactNode* NodeLoc) {
    ContactNode* tmpNext = nullptr;
    tmpNext = this->nextNodePtr;
    this->nextNodePtr = NodeLoc;
    NodeLoc->nextNodePtr = tmpNext;
}
