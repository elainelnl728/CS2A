//
//  PlaylistNode.hpp
//  Extra_credit_Project
//
//  Created by Niliang Lu on 6/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
// id: 20392734

#ifndef PlaylistNode_hpp
#define PlaylistNode_hpp

#include <string>
#include <stdio.h>

#include "SongEntry.h"
using namespace std;

class PlaylistNode {
private:
    SongEntry song;
    PlaylistNode *next;
public:
    PlaylistNode(const SongEntry& theSong=SongEntry()): song(theSong), next(nullptr) {}
    ~PlaylistNode(); // Do not free recursively
    const SongEntry& get_song() const { return song; }
    PlaylistNode *get_next() const { return next; }
    PlaylistNode *insert_next(PlaylistNode *p);
    PlaylistNode *remove_next();
    friend class Tests; // Don't remove this line
};
#endif /* PlaylistNode_hpp */
