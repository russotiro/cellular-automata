//
// Created by RussellS on 5/23/21.
//

#ifndef CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H
#define CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H

#include <string>

using namespace std;

class Cellular_automata {
public:
    Cellular_automata();

    void run(int rule);

private:
    static const int NUM_GENERATIONS = 100;
    static const int WIDTH           = 117;
    const string query_arr[8] = {"***", "** ", "* *", "*  ", " **", " * ", "  *", "   "};

    void extrapolate_rule(int rule);

    void advance_generation(int direction);
    char data[2][WIDTH]{};
    int rule_binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
};


#endif //CELLULAR_AUTOMATA_CELLULAR_AUTOMATA_H
