//
//  PlaylistNode.cpp
//  Extra_credit_Project
//
//  Created by Niliang Lu on 6/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
// id: 20392734

#include "PlaylistNode.h"

using namespace std;

PlaylistNode::~PlaylistNode() {}

PlaylistNode *PlaylistNode::insert_next(PlaylistNode *p) {
    if(p == nullptr) {
        return nullptr;
    }
    p->next = this->next;
    this->next = p;
    return this;
}

PlaylistNode *PlaylistNode::remove_next() {
    if(this->next == nullptr) {
        return nullptr;
    }
    PlaylistNode* temp = this->next->next;
    delete this->next;
    this->next = temp;
    return this;
}
