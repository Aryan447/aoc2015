#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void move(char c, int& x, int& y) {
    switch (c) {
        case '^':
            x++;
            break;
        case 'v':
            x--;
            break;
        case '>':
            y++;
            break;
        case '<':
            y--;
            break;
    }
}

int part1(const string& input) {
    int x = 0, y = 0;
    unordered_set<string> visited;
    visited.insert("0,0");

    for (char c : input) {
        move(c, x, y);

        visited.insert(to_string(x) + "," + to_string(y));
    }

    return visited.size();
}

int part2(const string& input) {
    int sx = 0, sy = 0;
    int rx = 0, ry = 0;

    unordered_set<string> visited;
    visited.insert("0,0");

    for (size_t i = 0; i < input.size(); i++) {
        int& x = (i % 2 == 0) ? sx : rx;
        int& y = (i % 2 == 0) ? sy : ry;

        move(input[i], x, y);

        visited.insert(to_string(x) + "," + to_string(y));
    }

    return visited.size();
}

int main() {
    ifstream file("day3.input");
    string input;
    getline(file, input);

    cout << "Part 1: " << part1(input) << "\n";
    cout << "Part 2: " << part2(input) << "\n";
}
