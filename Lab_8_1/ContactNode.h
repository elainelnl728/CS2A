//
//  ContactNode.hpp
//  HomeWork
//
//  Created by Elaine on 6/9/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#ifndef ContactNode_hpp
#define ContactNode_h

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class ContactNode {
public:
    ContactNode(string name, string PhoneNum);
    
    string GetName();
    string GetPhoneNumber();
    ContactNode* GetNext();
    void PrintContactNode();
    void InsertAfter(ContactNode* NodeLoc);
    
private:
    string contactName;
    string contactPhoneNum;
    ContactNode* nextNodePtr;
}
#endif /* ContactNode_hpp */
