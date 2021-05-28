//
// Created by RussellS on 5/27/21.
//

#include "Color_CA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Color_CA::Color_CA() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < WIDTH; i++) {
            data[0][i][k] = random_input ? rand() % COLOR_DEPTH : COLOR_DEPTH - 1;
            data[1][i][k] = COLOR_DEPTH - 1;
        }
        if (!random_input)
            data[0][WIDTH / 2][k] = 0;
    }
}

void Color_CA::run() {
    // .ppm file setup
    ofstream ca_img("color_ca.ppm");
    ca_img << "P3" << endl;
    ca_img << WIDTH << " " << NUM_GENERATIONS << endl;
    ca_img << COLOR_DEPTH - 1 << endl;

    for (int j = 0; j < NUM_GENERATIONS; j++) {
        for (int i = 0; i < WIDTH; i++) {
            for (int k = 0; k < 3; k++) {
                ca_img << data[j % 2][i][k] << ' ';
            }
        }
        ca_img << endl;
        advance_generation(j % 2);
    }

    ca_img.close();
}

void Color_CA::advance_generation(int direction) {
    int query[3][3];
    int width_index;
    int offset = single_neighbor_cells == "wrap" ? 0 : 1;
    for (int i = offset; i < WIDTH - offset; i++) {
        // Extrapolate 3-bit query from current row
        for (int j = 0; j < 9; j++) {
            width_index = (i + (j / 3) - 1 + WIDTH) % WIDTH;
            query[j / 3][j % 3] = data[direction][width_index][j % 3];
        }
        // Assign center color values of other row accordingly
        for (int j = 0; j < 3; j++) {
            data[1 - direction][i][j] = (query[0][j] + query[1][j] + query[2][j]) / 3;
        }
        // Assign single-neighbor cells for "fill" and "clear" modes
        for (int j = 0; j < 3; j++) {
            if (single_neighbor_cells == "fill") {
                data[1 - direction][0][j] = data[1 - direction][WIDTH - 1][j] = 0;
            } else if (single_neighbor_cells == "clear") {
                data[1 - direction][0][j] = data[1 - direction][WIDTH - 1][j] = COLOR_DEPTH - 1;
            }
        }
    }
}
