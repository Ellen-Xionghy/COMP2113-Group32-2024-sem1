#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;
struct Record {
    string name;
    int score;
};

void clear_screen();
Record* readRecords(const string& filename, int& size);
Record* insertWinner(Record* records, int& size, const string& winner, const int round);
void writeRecords(const string& filename, Record* records, int size);
void show_winnerlist(string player_name, int round);

#endif // MAIN_H


