#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("day1.input");
    if (!file.is_open()) {
        std::cerr << "Error: could not open day1.input\n";
        return 1;
    }

    std::string s;
    std::getline(file, s);

    int floor = 0;
    int position = 0;
    bool found = false;

    for (char c : s) {
        switch (c) {
            case '(':
                floor++;
                position++;
                break;
            case ')':
                floor--;
                position++;
                break;
            default:
                break;
        }
        if (floor == -1 && !found) {
            std::cout << "Floor -1 at position: " << position << "\n";
            found = true;
            break;
        }
    }

    if (!found) std::cout << "Never reached floor -1\n";

    std::cout << "Floor: " << floor << "\n";
}

