#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread> // for sleep_for
#include <chrono> // for milliseconds
#include <fstream>
#include "functions.h"
#include "drawmap.h"

using namespace std;


// input number of players
void input_num_of_players(int& num_of_players) {
    cout << "Enter the number of players (2-4): ";
    while (true) {
        cin >> num_of_players;
        if (num_of_players >= 2 && num_of_players <= 4) {
            break;
        }
        cout << "Invalid input! Please enter a number between 2 and 4: ";
    }
}

// Input name of players
void input_username(vector<string>& player_name, int num_of_players) {
    player_name.resize(num_of_players); // Resize the vector to hold player names
    for (int i = 0; i < num_of_players; ++i) {
        cout << "Enter the name of Player " << i + 1 << ": ";
        while (true) {
            getline(cin, player_name[i]);
            if (player_name[i].empty()) {
                cout << "Player name cannot be empty: ";
                continue;
            }
            bool duplicate = false;
            for (int j = 0; j < i; ++j) {
                if (player_name[i] == player_name[j]) {
                    cout << "Name already taken. Please enter a different name: ";
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) break;
        }
    }
}




// player play game one by one
void play_game(const vector<string>& player_name, vector<int>& player_cor, int player_id, int* maps, vector<bool>& paused) {
    string input;

    // rolling dice
    int dice_roll = rand() % 6 + 1; // 
    cout << player_name[player_id] << " rolls the dice: " << dice_roll << endl;

    // update players' position
    player_cor[player_id] += dice_roll;
    if (player_cor[player_id] >= 150){
    	int back =player_cor[player_id]-149;
    	player_cor[player_id]=149- back ;
    	cout << player_name[player_id] << " moves to position 150 and then back " << back << "." <<endl;
	}
    cout << player_name[player_id] << " moves to position " << player_cor[player_id] +1 << "." << endl;

    // check whether 2 players are in sameposition
    for (int i = 0; i < static_cast<int>(player_cor.size()); ++i) {
        if (i != player_id && player_cor[i] == player_cor[player_id]) {
            // if same position, the first player will move back 3 spaces
            cout << "Player " << player_name[i] << " was already at position " << player_cor[i]+1
                 << ", and will move back 3 spaces!" << endl;
            player_cor[i] -= 3;

            // ensure position >= 0
            if (player_cor[i] < 0) {
                player_cor[i] = 0;
            }
            cout << player_name[i] << " is now at position " << player_cor[i]+1 << "." << endl;
        }
    }

    
    
    switch (maps[player_cor[player_id]]) {
    case 1: // lucky
    {
        int bonus = rand() % 10 + 1; // random number from 1 to 10
        cout << player_name[player_id] << " lands on a lucky square and moves forward (randomly selected from 1-10)" << bonus << " spaces!" << endl;
        player_cor[player_id] += bonus;
        cout << player_name[player_id] << " moves to position " << player_cor[player_id] +1 << "." << endl;

        break;
    }
    case 2: // unlucky
    {
        int penalty = rand() % 3 + 1; // random number from 1 to 3
        cout << player_name[player_id] << " lands on an unlucky square and moves back(randomly selected from 1-3) " << penalty << " spaces!" << endl;
        player_cor[player_id] -= penalty;
        if (player_cor[player_id] < 0) {
            player_cor[player_id] = 0;
        }
        cout << player_name[player_id] << " moves to position " << player_cor[player_id] +1 << "." << endl;

        break;
    }
        case 3: // pause
            cout << player_name[player_id] << " lands on a stay-pause square and will skip their next turn!" << endl;
            paused[player_id] = true; // set pause sign
            break;
        case 4: // swap
            cout << player_name[player_id] << " lands on a switch-position square!(randomly select another player to switch positions with)" << endl;

            // random swap
            int random_player = rand() % player_cor.size();
            while (random_player == player_id) {
                random_player = rand() % player_cor.size();
            }

            cout << player_name[player_id] << " swaps position with " << player_name[random_player] << "!" << endl;
            swap(player_cor[player_id], player_cor[random_player]);
            cout << player_name[player_id] << " moves to position " << player_cor[player_id] +1 << "." << endl;
        	cout << player_name[random_player] << " moves to position " << player_cor[random_player] +1 << "." << endl;
            break;
    }

    // map visualization
    map_visualization(player_cor, maps);
}

void finish_game() {
	string lines[] = {
        " YY     YY      OOOOO     UUU   UUU        W     W     IIIII   NNN   NNN",
        "  YY   YY      OO   OO    UUU   UUU        W     W      III    NNNN  NNN",
        "   YY YY       OO   OO    UUU   UUU        W  W  W      III    NNN N NNN",
        "    YYY        OO   OO    UUU   UUU        W  W  W      III    NNN  NNNN",
        "    YYY         OOOOO      UUUUUUU          WW WW      IIIII   NNN   NNN"
    };

    for (const string& line : lines) {
        cout << line << endl;
        this_thread::sleep_for(chrono::milliseconds(300)); // delay 300ms for every line
    }


}

// show rules
void show_rules() {
    ifstream rules_file("Rules.txt");
    if (rules_file.is_open()) {
        string line;
        while (getline(rules_file, line)) {
            cout << line << endl;
        }
        rules_file.close();
    }
    else {
        cout << "Error during open files." << endl;
    }
}

// show lists
void show_lists() {
    ifstream rules_file("record.txt");
    if (rules_file.is_open()) {
        string line;
        while (getline(rules_file, line)) {
            cout << line << endl;
        }
        rules_file.close();
    }
    else {
        cout << "Error during open files." << endl;
    }
}


