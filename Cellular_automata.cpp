//
// Created by RussellS on 5/23/21.
//

#include "Cellular_automata.h"
#include <iostream>

using namespace std;

Cellular_automata::Cellular_automata() {
    for (int i = 0; i < WIDTH; i++) {
        data[0][i] = ' ';
        data[1][i] = ' ';
    }
    data[0][WIDTH / 2] = '*';
}

void Cellular_automata::run(int rule) {
    extrapolate_rule(rule);

    for (int j = 0; j < NUM_GENERATIONS; j++) {
        for (int i = 0; i < WIDTH; i++) {
            cout << data[j % 2][i];
        }
        cout << endl;
        advance_generation(j % 2);
    }
}

void Cellular_automata::extrapolate_rule(int rule) {
    rule_int = rule;
    // Big-endian
    for (int i = 7; rule > 0; i--) {
        rule_binary[i] = rule % 2;
        rule /= 2;
    }
}

void Cellular_automata::advance_generation(int direction) {
    string query;
    int offset = wrap_single_neighbor_cells ? 0 : 1;
    for (int i = offset; i < WIDTH - offset; i++) {
        // Extrapolate 3-bit query from current row
        query = {data[direction][(i - 1 + WIDTH) % WIDTH], data[direction][i], data[direction][(i + 1) % WIDTH]};
        // Assign center bit of other row accordingly
        for (int j = 0; j < 8; j++) {
            if (query == query_arr[j]) {
                data[1 - direction][i] = rule_binary[j] == 1 ? '*' : ' ';
            }
        }
        if (!wrap_single_neighbor_cells)
            data[1 - direction][0] = data[1 - direction][WIDTH - 1] = rule_int % 2 == 0 ? ' ' : '*';
    }
}
