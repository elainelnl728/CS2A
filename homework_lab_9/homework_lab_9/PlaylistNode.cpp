//
//  PlaylistNode.cpp
//  homework_lab_9
//
//  Created by Elaine on 6/23/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "PlaylistNode.h"

#include <iostream>
#include <string>
using namespace std;

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
}

PlaylistNode::PlaylistNode(const string& uniqueID, const string& songName, const string& artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
}

void PlaylistNode::InsertAfter(PlaylistNode* NodeLoc) {
    NodeLoc->SetNext(this->GetNext());
    this->SetNext(NodeLoc);
}

void PlaylistNode::SetNext(PlaylistNode* NodeLoc) {
    this->nextNodePtr = NodeLoc;
}

string PlaylistNode::GetID() {
    return this->uniqueID;
}

string PlaylistNode::GetSongName() {
    return this->songName;
}

string PlaylistNode::GetArtistName() {
    return this->artistName;
}

int PlaylistNode::GetSongLength() {
    return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}
