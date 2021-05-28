//
// Created by RussellS on 5/23/21.
//

#include "Elementary_CA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

Elementary_CA::Elementary_CA() {
    for (int i = 0; i < WIDTH; i++) {
        data[0][i] = random_input ? (rand() % 2 == 1 ? '1' : '0') : '0';
        data[1][i] = '0';
    }
    if (!random_input)
        data[0][WIDTH / 2] = '1';
}

void Elementary_CA::run(int rule) {
    extrapolate_rule(rule);

    // .pbm file setup
    ofstream ca_img("elem_ca_r#" + to_string(rule) + ".pbm");
    ca_img << "P1" << endl;
    ca_img << WIDTH << " " << NUM_GENERATIONS << endl;

    for (int j = 0; j < NUM_GENERATIONS; j++) {
        for (int i = 0; i < WIDTH; i++) {
            ca_img << data[j % 2][i] << ' ';
        }
        ca_img << endl;
        advance_generation(j % 2);
    }

    ca_img.close();
}

void Elementary_CA::extrapolate_rule(int rule) {
    // Big-endian
    for (int i = 7; rule > 0; i--) {
        rule_binary[i] = rule % 2;
        rule /= 2;
    }
}

void Elementary_CA::advance_generation(int direction) {
    string query;
    int offset = single_neighbor_cells == "wrap" ? 0 : 1;
    for (int i = offset; i < WIDTH - offset; i++) {
        // Extrapolate 3-bit query from current row
        query = {data[direction][(i - 1 + WIDTH) % WIDTH], data[direction][i], data[direction][(i + 1) % WIDTH]};
        // Assign center bit of other row accordingly
        for (int j = 0; j < 8; j++) {
            if (query == query_arr[j]) {
                data[1 - direction][i] = rule_binary[j] == 1 ? '1' : '0';
            }
        }
        // Assign single-neighbor cells for "fill" and "clear" modes
        if (single_neighbor_cells == "fill") {
            data[1 - direction][0] = data[1 - direction][WIDTH - 1] = '1';
        } else if (single_neighbor_cells == "clear") {
            data[1 - direction][0] = data[1 - direction][WIDTH - 1] = '0';
        }
    }
}

string Elementary_CA::to_string(int value) {
    ostringstream my_ss;
    my_ss << value;
    return my_ss.str();
}
