#include <iostream>

const int NUM_GENERATIONS = 256;
const int WIDTH           = 117;

using namespace std;

void advance_generation(char data[2][WIDTH], int direction);

int main() {

    char data[2][WIDTH];

    // Initialize data array
    for (int i = 0; i < WIDTH; i++) {
        data[0][i] = ' ';
        data[1][i] = ' ';
    }
    data[0][WIDTH / 2] = '*';

    // Main computations and printing
    for (int j = 0; j < NUM_GENERATIONS; j++) {
        for (int i = 0; i < WIDTH; i++) {
            advance_generation(data, j % 2);
            cout << data[j % 2][i];
        }
        cout << endl;
    }
}

void advance_generation(char data[2][WIDTH], int direction) {
    for (int i = 0; i < WIDTH - 2; i++) {
        string query = {data[direction][i], data[direction][i + 1], data[direction][i + 2]};
        if (query == "***")
            data[1 - direction][i + 1] = ' ';
        else if (query == "** ")
            data[1 - direction][i + 1] = ' ';
        else if (query == "* *")
            data[1 - direction][i + 1] = ' ';
        else if (query == "*  ")
            data[1 - direction][i + 1] = '*';
        else if (query == " **")
            data[1 - direction][i + 1] = '*';
        else if (query == " * ")
            data[1 - direction][i + 1] = '*';
        else if (query == "  *")
            data[1 - direction][i + 1] = '*';
        else if (query == "   ")
            data[1 - direction][i + 1] = ' ';
    }
}