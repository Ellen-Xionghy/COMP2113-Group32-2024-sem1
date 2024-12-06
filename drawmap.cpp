#include <iostream>
#include <vector>
#include <string>
#include "drawmap.h"

using namespace std;

// draw title
void drawtitle() {
    cout << "==========================================" << endl;
    cout << "          Welcome to the Board Game       " << endl;
    cout << "==========================================" << endl;
}

// map initialization
void map_initialization(int* maps) {
    for (int i = 0; i < 150; ++i) {
        maps[i] = 0; // every square is nomal (initialization)

        // special squares
        if (i % 13 == 9) {
            maps[i] = 1; // lucky square
        } else if (i % 11 == 9) {
            maps[i] = 2; // unlucky square
        } else if (i % 20 == 13) {
            maps[i] = 3; // pause square
        } else if (i % 25 == 19) {
            maps[i] = 4; // swap square
        }
    }
}

void map_visualization(const vector<int>& player_cor, const int* maps) {
    const int row_size = 30; 
    const int total_size = 150; 
    cout << "(luckydraw:+  badluck:@  staypause:*  changeposition:%)" << endl;
    
        for (int i = 0; i < total_size; ++i) {
        bool ifmore_players = false; //To see whether there are more than one player staying here
        int player_index = -1;          // record the player's index staying here

        // To check whether there are more than one player staying here
        for (int j = 0; j < static_cast<int>(player_cor.size()); ++j) {
            if (player_cor[j] == i) {
                if (player_index == -1) {
                    player_index = j; // record the first player staying here
                } else {
                    ifmore_players = true; // it means there is already a player staying here
                    break;
                }
            }
        }

        // more than one player staying here
        if (ifmore_players) {
            cout << "&";
        }
        // only one player staying--output the player's num
        else if (player_index != -1) {
            cout << player_index + 1; 
        }
        else {
            switch (maps[i]) {
                case 1: // lucky square
                    cout << "+";
                    break;
                case 2: //unlucky square
                    cout << "@";
                    break;
                case 3: // pause square
                    cout << "*";
                    break;
                case 4: // switch square
                    cout << "%";
                    break;
                default: // normal square
                    cout << "#";
                    break;
            }
        }   
        if ((i + 1) % row_size == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// print player name
void print_player_name(int num_of_players, const vector<string>& player_name) {
    cout << "Players: ";
    for (int i = 0; i < num_of_players; ++i) {
        cout << player_name[i];
        if (i != num_of_players - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}
