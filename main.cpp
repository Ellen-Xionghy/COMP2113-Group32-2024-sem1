#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h> // For sleep()
#include "functions.h"
#include "drawmap.h"
#include "main.h"

using namespace std;

// clear screen
void clear_screen() {
    cout << string(50, '\n');
}

int main() {
    srand(time(0));
    int choice;
    int num_of_players = 0; 
    vector<int> player_cor;
    int rounds = 0;
    vector<string> player_name(num_of_players); 
    vector<bool> paused;
    int maps[150] = {0};	

    

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Show winner list" << endl;
        cout << "3. Show Rules" << endl;
        cout << "4. Exit Game" << endl;
        cin >> choice;

        switch (choice) {
        case 1: // New Game
            cout << "Enter number of players: ";
            input_num_of_players(num_of_players); // Input number of players
            player_name.resize(num_of_players);   
			paused.resize(num_of_players, false); 
            player_cor = vector<int>(num_of_players, 0); // Player positions
            rounds = 0; // Reset rounds
            break;

        case 2: // show winner list
            show_lists();
            continue;

        case 3: // Show Rules
            show_rules();
            continue;

        case 4: // Exit Game
            cout << "Exiting game." << endl;
            return 0;

        default:
            cout << "Invalid input, please try again." << endl;
            continue;
        }

        // **Game Title and Player Input**
        drawtitle(); // Display game title

        input_username(player_name, num_of_players); // Input player names
        sleep(1); // Delay 1 second
        clear_screen(); // Clear screen

        // **Display Player Information**
        drawtitle();
        print_player_name(num_of_players, player_name); // Display player names
        cout << "(luckydraw:+  badluck:@  staypause:*  changeposition:%)" << endl;

        // **Map Initialization**
        clear_screen();
        map_initialization(maps);
        map_visualization(player_cor, maps); // Display initial map

        // **Main Game Loop**
        while (true) {
            // Turn-based player actions
            for (int i = 0; i < num_of_players; ++i) {
                rounds++ ; // Increment round count
                // Skip paused players
                if (paused[i]) {
                    cout << player_name[i] << " is paused this round and will skip their turn." << endl;
                    paused[i] = false; // Clear pause status
                    continue;
                }
				
				cout << player_name[i] << ", press 'c' to roll the dice (or 'q' to quit): ";
        		while (true) {
        			string input;
            		getline(cin, input);
            		if (input == "q") {
                		cout << " Exiting..." << endl;
                		return 0; 
            		} else if (input == "c") {
                		break; 
            		} else {
                		cout << "Invalid input! Press 'c' to roll the dice (or 'q' to quit): ";
            		}
        		}
				
                // Player action
                play_game(player_name, player_cor, i, maps, paused);

                // Check for victory condition
                if (player_cor[i] == 149) {
                    cout << " Congratulations! Player " << player_name[i] << " wins the game! " << endl;


                    // Check if other players also reached the finish line
                    for (int j = 0; j < num_of_players; ++j) {
                        if (j != i && player_cor[j] == 150) {
                            cout << "Player " << player_name[j] << " also reaches the finish line!" << endl;
                        }
                    }

                    finish_game(); // End game
                    show_winnerlist(player_name[i], rounds);
                    show_lists();
                    return 0; // Exit program
                }
            }
        }
    }

    return 0;
}


Record* readRecords(const string& filename, int& size) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        size = 0;
        return nullptr;
    }
    vector<Record> records;
    Record temp;
    while (infile >> temp.name >> temp.score) {
        records.push_back(temp);
    }
    infile.close();
    size = records.size();
    Record* recordArray = new Record[size];
    for (int i = 0; i < size; ++i) {
        recordArray[i] = records[i];
    }
    return recordArray;
}


Record* insertWinner(Record* records, int& size, const string& winner, const int round) {
    Record newRecord = {winner, round};
    Record* newRecords = new Record[size + 1];
    int i = 0, j = 0;
    while (i < size && records[i].score < newRecord.score) {
        newRecords[j++] = records[i++];
    }
    newRecords[j++] = newRecord;
    while (i < size) {
        newRecords[j++] = records[i++];
    }
    delete[] records;
    size++;
    return newRecords;
}

void writeRecords(const string& filename, Record* records, int size) {
    ofstream outfile(filename);
    for (int i = 0; i < size; ++i) {
        outfile << records[i].name << " " << records[i].score << "\n";
    }
}

void show_winnerlist(string player_name, int round) {
    const string filename = "record.txt";
    int size;
    Record* records = readRecords(filename, size);
    records = insertWinner(records, size, player_name, round);
    writeRecords(filename, records, size);
    delete[] records;
    cout << "Winner list updated successfully!" << endl;
}





