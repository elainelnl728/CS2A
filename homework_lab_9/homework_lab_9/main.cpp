//
//  main.cpp
//  homework_lab_9
//
//  Created by Elaine on 6/23/19.
//  Copyright © 2019 Elaine. All rights reserved.
//

#include "PlaylistNode.h"

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

void EmptyLine() {
    cout << endl;
}

void PrintMenu(const string& playlistTitle) {
    char option = '\0';
    int numNode = 0;
    PlaylistNode* headNode = nullptr;
    PlaylistNode* lastNode = nullptr;
    
    const string menu = playlistTitle + " PLAYLIST MENU\na - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit\n";
    cout << menu;
    EmptyLine();
    
    while (true) {
        cout << "Choose an option:" << endl;
        cin >> option;
        
        switch (option) {
            case 'q':
                return;
            case 'a': {
                string uniqueID;
                string songName;
                string artistName;
                int songLength;
                cout << "ADD SONG" << endl;
                cout << "Enter song's unique ID:" << endl;
                cin.ignore();
                getline(cin, uniqueID);
                cout << "Enter song's name:" << endl;
//                cin.ignore();
                getline(cin, songName);
                cout << "Enter artist's name:" << endl;
//                cin.ignore();
                getline(cin, artistName);
                cout << "Enter song's length (in seconds):" << endl;
                cin >> songLength;
                PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
                if (lastNode == nullptr) {
                    headNode = newNode;
                    lastNode = newNode;
                } else {
                    lastNode->InsertAfter(newNode);
                    lastNode = lastNode->GetNext();
                }
                numNode += 1;
                EmptyLine();
                
                cout << menu << endl;
                break;
            }
            case 'd': {
                cout << "REMOVE SONG" << endl;
                cout << "Enter song's unique ID:" << endl;
                cin.ignore();
                string uniqueID;
                getline(cin, uniqueID);
                PlaylistNode* preNode = nullptr;
                PlaylistNode* currNode = headNode;
                while (currNode != nullptr && currNode->GetID() != uniqueID) {
                    preNode = currNode;
                    currNode = currNode->GetNext();
                }
                if (currNode != nullptr) {
                    if (preNode == nullptr) {
                        headNode = currNode->GetNext();
                        if (currNode->GetNext() == nullptr) {
                            lastNode = preNode;
                        }
                    } else {
                        preNode->SetNext(currNode->GetNext());
                        if (currNode->GetNext() == nullptr) {
                            lastNode = preNode;
                        }
                    }
                    cout << "\"" << currNode->GetSongName() << "\" removed." << endl;
                    delete currNode;
                    numNode -= 1;
                }
                EmptyLine();
                
                cout << menu << endl;
                break;
            }
            case 'c': {
                int currPos;
                int newPos;
                cout << "CHANGE POSITION OF SONG" << endl;
                cout << "Enter song's current position:" << endl;
                cin >> currPos;
                cout << "Enter new position for song:" << endl;
                cin >> newPos;
                currPos = max(1, currPos);
                currPos = min(currPos, numNode);
                newPos = max(1, newPos);
                newPos = min(newPos, numNode);
                
                // Find node at current positive and before new position.
                PlaylistNode* preNode = nullptr;
                PlaylistNode* currNode = headNode;
                int nodeIndex = 1;
                PlaylistNode* preCurrPosNode = nullptr;
                PlaylistNode* currPosNode = nullptr;
                PlaylistNode* preNewPosNode = nullptr;
                PlaylistNode* newPosNode = nullptr;
                while (currNode != nullptr) {
                    if (nodeIndex == currPos) {
                        preCurrPosNode = preNode;
                        currPosNode = currNode;
                    }
                    if (nodeIndex == newPos) {
                        preNewPosNode = preNode;
                        newPosNode = currNode;
                    }
                    nodeIndex++;
                    preNode = currNode;
                    currNode = currNode->GetNext();
                }
                
                if (currPos != newPos) {
                    if (preCurrPosNode == nullptr) {
                        // Current position node is head node.
                        headNode = currPosNode->GetNext();
                        if (currPosNode->GetNext() == nullptr) {
                            // Current position node is tail node.
                            lastNode = preCurrPosNode;
                        }
                    } else {
                        preCurrPosNode->SetNext(currPosNode->GetNext());
                        if (currPosNode->GetNext() == nullptr) {
                            // Current position node is tail node.
                            lastNode = preCurrPosNode;
                        }
                    }
                    if (preNewPosNode == nullptr) {
                        // Move node to head.
                        currPosNode->SetNext(headNode);
                        headNode = currPosNode;
                        if (newPosNode->GetNext() == nullptr) {
                            // Current position node is tail node.
                            lastNode = currPosNode;
                        }
                    } else {
                        if (currPos < newPos) {
                            newPosNode->InsertAfter(currPosNode);
                        } else {
                            preNewPosNode->InsertAfter(currPosNode);
                        }
                        if (newPosNode->GetNext() == nullptr) {
                            // Current position node is tail node.
                            lastNode = currPosNode;
                        }
                    }
                }
                cout << "\"" << currPosNode->GetSongName() << "\" moved to position " << newPos << endl;
                EmptyLine();
                
                cout << menu << endl;
                break;
            }
            case 's': {
                cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
                cout << "Enter artist's name:" << endl;
                string artistName;
                cin.ignore();
                getline(cin, artistName);
                EmptyLine();
                
                PlaylistNode* currNode = headNode;
                int nodeIndex = 1;
                while (currNode != nullptr) {
                    if (currNode->GetArtistName() == artistName) {
                        cout << nodeIndex << "." << endl;
                        currNode->PrintPlaylistNode();
                        EmptyLine();
                    }
                    currNode = currNode->GetNext();
                    nodeIndex += 1;
                }
                
                cout << menu << endl;
                break;
            }
            case 't': {
                cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
                
                PlaylistNode* currNode = headNode;
                int totalTime = 0;
                while (currNode != nullptr) {
                    totalTime += currNode->GetSongLength();
                    currNode = currNode->GetNext();
                }
                cout << "Total time: " << totalTime << " seconds" << endl;
                EmptyLine();
                
                cout << menu << endl;
                break;
            }
            case 'o': {
                cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
                if (headNode == nullptr) {
                    cout << "Playlist is empty\n";
                    EmptyLine();
                } else {
                    int countNode = 1;
                    PlaylistNode* currNode = headNode;
                    while (currNode != nullptr) {
                        cout << countNode << '.' << endl;
                        currNode->PrintPlaylistNode();
                        EmptyLine();
                        currNode = currNode->GetNext();
                        countNode++;
                    }
                }

                cout << menu << endl;
                break;
            }

        }
    }
}

int main(int argc, const char * argv[]) {
    string playlistTitle;
    string currentDate;
    PlaylistNode PlaylistNode;
    
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    
    EmptyLine();
    
    PrintMenu(playlistTitle);

    return 0;
}
