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
        advance_generation(j % 2);
        for (int i = 0; i < WIDTH; i++) {
            cout << data[j % 2][i];
        }
        cout << endl;
    }
}

void Cellular_automata::extrapolate_rule(int rule) {
    // Big-endian :(
    for (int i = 7; rule > 0; i--) {
        rule_binary[i] = rule % 2;
        rule /= 2;
    }
}

void Cellular_automata::advance_generation(int direction) {
    string query;
    char new_bit;
    for (int i = 1; i < WIDTH - 1; i++) {
        query = {data[direction][i - 1], data[direction][i], data[direction][i + 1]};
        for (int j = 0; j < 8; j++) {
            if (query == query_arr[j]) {
                new_bit = rule_binary[j] == 1 ? '*' : ' ';
            }
        }
        data[1 - direction][i] = new_bit;
    }
}
