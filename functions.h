#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;


void input_num_of_players(int& num_of_players);
void input_username(std::vector<std::string>& player_name, int num_of_players);
void play_game(const std::vector<std::string>& player_name, std::vector<int>& player_cor, int player_id, int* maps, std::vector<bool>& paused);
void finish_game();
void show_rules();
void show_lists();
#endif


