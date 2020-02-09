//
//  SongEntry.hpp
//  Extra_credit_Project
//
//  Created by Niliang Lu on 6/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
// id: 20392734

#ifndef SongEntry_hpp
#define SongEntry_hpp

#include <string>
#include <stdio.h>
using namespace std;

class SongEntry {
private:
    int id;
    string name;
public:
    SongEntry(int theId = 0, string theName = "Unnamed") : id(theId), name(theName) {}
    int get_id() const { return id; }
    string get_name() const { return name; }
    bool set_id(int id);
    bool set_name(string theName);
    friend class Tests; // Don't remove this line
};
#endif /* SongEntry_hpp */
