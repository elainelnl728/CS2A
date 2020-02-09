//
//  Playlist.cpp
//  Extra_credit_Project
//
//  Created by Niliang Lu on 6/30/19.
//  Copyright © 2019 Elaine. All rights reserved.
// id: 20392734

#include <iomanip>
#include <iostream>
using namespace std;

#include "Playlist.h"

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

PlaylistNode::~PlaylistNode() {}

PlaylistNode *PlaylistNode::insert_next(PlaylistNode *p) {
    if(p == nullptr) {
        return nullptr;
    }
    p->next = this->next;
    this->next = p;
    return this;
}

PlaylistNode *PlaylistNode: :remove_next() {
    if(this->next == nullptr) {
        return nullptr;
    }
    PlaylistNode* temp = this->next->next;
    delete this->next;
    this->next = temp;
    return this;
}

//////////////////////////////////////////////////
Playlist::Playlist() {
    SongEntry songEntry(0, "Header");
    this->head = new PlaylistNode(songEntry);
    this->tail = this->head;
    this->prevToCurr = this->head;
    this->size = 0;
    
    this->counter_front = 0;  // test
    this->counter_back = 0;  // test
    this->counter_get_curr = 0; // test
    this->counter_advance = 0;  // test
    this->counter_circle = 0; // test
    this->counter_operation = 0;  // test
}

Playlist::~Playlist() {
    while (head->remove_next() != nullptr) {}
    delete head;
}

Playlist *Playlist::clear() {
    while (this->head->remove_next() != nullptr) {}
    this->tail = this->head;
    this->prevToCurr = this->head;
    this->size = 0;
    
    this->counter_front = 0;  // test
    this->counter_back = 0;  // test
    this->counter_get_curr = 0; // test
    this->counter_advance = 0;  // test
    this->counter_circle = 0; // test
    this->counter_operation = 0;  // test
    
    return this;
}

PlaylistNode *Playlist::get_current_node() /*const*/ {
    if (head->get_next() == nullptr) {
        return nullptr;
    }
    
    // test
    auto tmp = prevToCurr->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " get_curr: " + to_string(this->counter_get_curr++));
    
    return prevToCurr->get_next();
}

Playlist *Playlist::rewind() {
    prevToCurr = head;
    return this;
}

// State of ​prevToCurr​ is ​undefined​ if ​advance​ returns a null pointer.
Playlist *Playlist::advance_curr_to_next() {
//    if (prevToCurr == nullptr ||
//        prevToCurr->get_next() == nullptr ||
//        prevToCurr->get_next()->get_next() == nullptr) {
//        return nullptr;
//    }
//    prevToCurr = prevToCurr->get_next();
//    return this;
    
    if (prevToCurr->get_next() != nullptr && prevToCurr->get_next()->get_next() == nullptr) {
        // test
        auto tmp = prevToCurr->get_mutable_song();
        tmp->set_debug(tmp->get_debug() + " not_move_pre_curr: " + to_string(tmp->get_id()));
        
        return nullptr;
    }
    
    prevToCurr = prevToCurr->get_next();
    if(prevToCurr == nullptr) {
        return nullptr;
    }
    
    // test
    auto tmp = prevToCurr->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " pre_curr" + to_string(this->counter_advance++) + ": " + to_string(tmp->get_id()));
    
    return this;
}

Playlist *Playlist::circular_advance_curr_to_next() {
    // Empty playlist.
    if (head->get_next() == nullptr) {
        return nullptr;
    }
    if (prevToCurr->get_next() == nullptr || prevToCurr->get_next()->get_next() == nullptr) {
        return rewind();
    }
    prevToCurr = prevToCurr->get_next();
    
    // test
    auto tmp = prevToCurr->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " circle_pre_curr" + to_string(this->counter_advance++) + ": " + to_string(tmp->get_id()));
    
    return this;
}

Playlist *Playlist::push_back(PlaylistNode *p) {
    if (p == nullptr) {
        return nullptr;
    }
    
    // test
    if (p->get_next() != nullptr) {
        auto tmp = p->get_mutable_song();
        tmp->set_debug(tmp->get_debug() + " back not null error!!!");
    }
    
    if (tail->insert_next(p) == nullptr) {
        return nullptr;
    }
    
    tail = tail->get_next();
    
    // test
    auto tmp = p->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " back: " + to_string(this->counter_operation++) + " pre_id: " + to_string(prevToCurr->get_song().get_id()) + " tail_id: " + to_string(tail->get_song().get_id()));
    
    size++;
    return this;
}

Playlist *Playlist::push_front(PlaylistNode *p) {
    if (p == nullptr) {
        return nullptr;
    }
    
    // test
    if (p->get_next() != nullptr) {
        auto tmp = p->get_mutable_song();
        tmp->set_debug(tmp->get_debug() + " front not null error!!!");
    }
    
    if (head->insert_next(p) == nullptr) {
        return nullptr;
    }
    if (p->get_next() == nullptr) {
        tail = p;
    }
    
    // test
    auto tmp = p->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " front: " + to_string(this->counter_operation++) + " pre_id: " + to_string(prevToCurr->get_song().get_id()) + " tail_id: " + to_string(tail->get_song().get_id()));
    
    size++;
    return this;
}

Playlist *Playlist::insert_at_curr(PlaylistNode *p) {
    if (p == nullptr) {
        return nullptr;
    }
    
    // test
    auto tmp = prevToCurr->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " insert: " + to_string(this->counter_operation++) + " insert_pre_curr: " + to_string(tmp->get_id()) + " inserted_id: " + to_string(p->get_song().get_id()));
    
    prevToCurr->insert_next(p);
    if (p->get_next() == nullptr) {
        tail = p;
    }
    size++;
    return this;
}

Playlist *Playlist::remove_at_curr() {
    if (prevToCurr->get_next() == nullptr) {
        return nullptr;
    }
    
    // test
    auto tmp = prevToCurr->get_mutable_song();
    tmp->set_debug(tmp->get_debug() + " remove: " + to_string(this->counter_operation++) + " remove_pre_curr: " + to_string(tmp->get_id()) + " removed_id: " + to_string(prevToCurr->get_next()->get_song().get_id()));
    
    prevToCurr->remove_next();
    if (prevToCurr->get_next() == nullptr) {
        tail = prevToCurr;
    }
    
    size--;
    return this;
}

PlaylistNode *Playlist::find_by_id(int id) const {
    PlaylistNode *currNode = head->get_next();
    while (currNode != nullptr) {
        if (currNode->get_song().get_id() == id) {
            // test
            auto tmp = currNode->get_mutable_song();
            tmp->set_debug(tmp->get_debug() + " find: " + to_string(this->counter_operation++) + " find_id: " + to_string(tmp->get_id()));
            
            return currNode;
        }
        currNode = currNode->get_next();
    }
    // Not found.
    return nullptr;
}

PlaylistNode *Playlist::find_by_song_name(string songName) const {
    PlaylistNode *currNode = head->get_next();
    while (currNode != nullptr) {
        if (currNode->get_song().get_name() == songName) {
            // test
            auto tmp = currNode->get_mutable_song();
            tmp->set_debug(tmp->get_debug() + " find: " + to_string(this->counter_operation++) + " find_id: " + to_string(tmp->get_id()));
            
            return currNode;
        }
        currNode = currNode->get_next();
    }
    // Not found.
    return nullptr;
}

string Playlist::toString() const {
    string output = "Playlist:​ ​" + to_string(size) +"​ ​entries.";
    if (head == nullptr) {
        return output;
    }
    PlaylistNode *currNode = head->get_next();
    while (currNode != nullptr) {
        char buffer[50];
        sprintf(buffer, "%05d", currNode->get_song().get_id());
        string id(buffer);
        output = output + "\nID​ ​" + id /*+ ":​ " + currNode->get_song().get_name()*/;
        // test
        output = output + "_debug: " + currNode->get_song().get_debug();
        currNode = currNode->get_next();
    }
    output = output + "\n";
    return output;
}

