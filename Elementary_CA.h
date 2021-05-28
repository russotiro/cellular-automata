//
// Created by RussellS on 5/23/21.
//

// Some fun rules: 30, 45, 90, 110, 225

#ifndef ELEMENTARY_CA_H
#define ELEMENTARY_CA_H

#include <string>

using namespace std;

class Elementary_CA {
public:
    Elementary_CA();

    void run(int rule);

private:
    static const int NUM_GENERATIONS = 1024;
    static const int WIDTH           = 511;
    const string query_arr[8] = {"111", "110", "101", "100", "011", "010", "001", "000"};

    void extrapolate_rule(int rule);
    void advance_generation(int direction);

    char data[2][WIDTH];
    int rule_binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    string single_neighbor_cells = "wrap"; // "wrap", "fill", or "clear"
    bool random_input = true;

    static string to_string(int value);
};


#endif //ELEMENTARY_CA_H
