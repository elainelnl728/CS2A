//
//  SongEntry.cpp
//  Extra_credit_Project
//
//  Created by Niliang Lu on 6/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
// id: 20392734

#include "SongEntry.h"

bool SongEntry::set_id(int id) {
    if (id < 0) {
        return false;
    }
    this->id = id;
    return true;
}

bool SongEntry::set_name(string theName) {
    if (theName == "") {
        return false;
    }
    this->name = theName;
    return true;
}


