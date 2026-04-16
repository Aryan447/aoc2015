#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

const int N = 1000;

enum OP { ON, OFF, TOGGLE };

OP getOP(const std::string& line) {
    if (line.find("turn on") == 0) return ON;
    if (line.find("turn off") == 0) return OFF;
    return TOGGLE;
}

void part1(bool grid[N][N], const std::string& line) {
    int x1, x2, y1, y2;

    OP op = getOP(line);

    switch (op) {
        case ON:
            std::sscanf(line.c_str(),
                        "turn on %d,%d through %d,%d",
                        &x1,
                        &y1,
                        &x2,
                        &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    grid[i][j] = true;
                }
            }
            break;
        case OFF:
            std::sscanf(line.c_str(),
                        "turn off %d,%d through %d,%d",
                        &x1,
                        &y1,
                        &x2,
                        &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    grid[i][j] = false;
                }
            }
            break;
        case TOGGLE:
            std::sscanf(
                line.c_str(), "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
            break;
    }
}

int countLights(bool grid[N][N]) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) count++;
        }
    }

    return count;
}

void part2(int grid[N][N], const std::string& line) {
    int x1, x2, y1, y2;

    OP op = getOP(line);

    switch (op) {
        case ON:
            std::sscanf(line.c_str(),
                        "turn on %d,%d through %d,%d",
                        &x1,
                        &y1,
                        &x2,
                        &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    grid[i][j] += 1;
                }
            }
            break;

        case OFF:
            std::sscanf(line.c_str(),
                        "turn off %d,%d through %d,%d",
                        &x1,
                        &y1,
                        &x2,
                        &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (grid[i][j]) grid[i][j] -= 1;
                }
            }
            break;

        case TOGGLE:
            std::sscanf(
                line.c_str(), "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    grid[i][j] += 2;
                }
            }
            break;
    }
}

long long countBrightness(const int grid[N][N]) {
    long long sum = 0;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            sum += grid[i][j];
        }
    }

    return sum;
}

int main() {
    std::ifstream file("day6.input");
    std::string line;

    static bool grid[N][N] = {};
    static int grid2[N][N] = {};

    while (std::getline(file, line)) {
        part1(grid, line);
    }
    std::cout << countLights(grid) << "\n";

    file.clear();
    file.seekg(0);

    while (std::getline(file, line)) {
        part2(grid2, line);
    }
    std::cout << countBrightness(grid2) << "\n";
}

