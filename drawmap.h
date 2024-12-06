#ifndef DRAWMAP_H
#define DRAWMAP_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// function declaration
void drawtitle(); 
void map_initialization(int* maps);
void map_visualization(const std::vector<int>& player_cor, const int* maps);
void print_player_name(int num_of_players, const std::vector<std::string>& player_name);

#endif


