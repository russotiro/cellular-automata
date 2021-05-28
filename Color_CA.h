//
// Created by RussellS on 5/27/21.
//

#ifndef COLOR_CA_H
#define COLOR_CA_H

#include <string>

using namespace std;

class Color_CA {
public:
    Color_CA();

    void run();

private:
    static const int NUM_GENERATIONS = 511;
    static const int WIDTH           = 511;
    static const int COLOR_DEPTH     = 16; // number of values for RGB

    void advance_generation(int direction);

    int data[2][WIDTH][3];
    string single_neighbor_cells = "wrap"; // "wrap", "fill", or "clear"
    bool random_input = true;
};


#endif //COLOR_CA_H
