//
// Created by RussellS on 5/23/21.
//

// Some fun rules: 30, 45, 90, 110, 225

#ifndef CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H
#define CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H

#include <string>

using namespace std;

class Cellular_automata {
public:
    Cellular_automata();

    void run(int rule);

private:
    static const int NUM_GENERATIONS = 1024;
    static const int WIDTH           = 455;
    const string query_arr[8] = {"111", "110", "101", "100", "011", "010", "001", "000"};

    void extrapolate_rule(int rule);
    void advance_generation(int direction);

    char data[2][WIDTH];
    int rule_binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int rule_int;
    string single_neighbor_cells = "wrap"; // "wrap", "fill", or "clear"
    bool random_input = false;
};


#endif //CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H
