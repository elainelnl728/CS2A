//
//  PlaylistNode.hpp
//  homework_lab_9
//
//  Created by Elaine on 6/23/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#ifndef PlaylistNode_hpp
#define PlaylistNode_hpp

#include <stdio.h>
#include <string>

using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    // For string type, use const reference to avoid copy operation.
    PlaylistNode(const string& uniqueID, const string& songName, const string& artistName, int songLength);
    void InsertAfter(PlaylistNode* NodeLoc);
    void SetNext(PlaylistNode* NodeLoc);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif /* PlaylistNode_hpp */
