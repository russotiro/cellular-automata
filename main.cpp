#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Elementary_CA.h"
#include "Color_CA.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cerr << "Error: Please specify the rule number as a command-line argument." << endl;
        exit(EXIT_FAILURE);
    } else if (argc > 2) {
        cerr << "Error: Too many command-lind arguments." << endl;
        exit(EXIT_FAILURE);
    }

    int rule = strtol(argv[1], nullptr, 10);

    if (rule < 0 or rule > 255) {
        cerr << "Error: Rule number must be in range [0, 255]." << endl;
        exit(EXIT_FAILURE);
    }

    srand(time(nullptr));

    Elementary_CA ca1;
    ca1.run(rule);

    Color_CA ca2;
    ca2.run();

    return 0;
}

/* TODO:
 * make more stuff customizable from the command line
 * maybe add GUI?
 */