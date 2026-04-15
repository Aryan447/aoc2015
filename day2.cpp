#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("day2.input");

    long long totalPaper = 0;
    long long totalRibbon = 0;

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        int l, w, h;

        std::sscanf(line.c_str(), "%dx%dx%d", &l, &w, &h);

        int area = 2 * (l * w + w * h + l * h);
        int extra = std::min({l * w, w * h, l * h});
        totalPaper += area + extra;

        int perimeter = 2 * (l + w + h - std::max({l, w, h}));
        int bow = l * w * h;

        totalRibbon += perimeter + bow;
    }

    std::cout << totalPaper << "\n";
    std::cout << totalRibbon << "\n";
}
