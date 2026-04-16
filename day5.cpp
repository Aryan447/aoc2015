#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

bool isNice(const std::string& s) {
    int vowels = 0;
    bool hasdouble = false;

    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];

        // vowel count
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels++;

        if (i > 0) {
            // double letter
            if (s[i] == s[i - 1]) hasdouble = true;

            // forbidden pairs
            char p = s[i - 1];
            if ((p == 'a' && c == 'b') || (p == 'c' && c == 'd')
                || (p == 'p' && c == 'q') || (p == 'x' && c == 'y')) {
                return false;
            }
        }
    }

    return vowels >= 3 && hasdouble;
}

bool isNice2(const std::string& s) {
    bool pairFound = false;
    bool repeatFound = false;

    std::unordered_map<std::string, size_t> seen;

    for (size_t i = 0; i < s.size(); i++) {
        // condition 2: s[i] == s[i+2]
        if (i + 2 < s.size() && s[i] == s[i + 2]) {
            repeatFound = true;
        }

        // condition 1: pair repeat
        if (i + 1 < s.size()) {
            std::string pair = s.substr(i, 2);

            if (seen.count(pair) && seen[pair] < i - 1) {
                pairFound = true;
            }

            if (!seen.count(pair)) {
                seen[pair] = i;
            }
        }
    }

    return pairFound && repeatFound;
}

int main() {
    std::ifstream file("day5.input");
    std::string line;

    int niceStrings = 0;
    int niceStrings2 = 0;

    while (std::getline(file, line)) {
        if (isNice(line)) niceStrings++;
    }

    file.clear();
    file.seekg(0);

    while (std::getline(file, line)) {
        if (isNice2(line)) niceStrings2++;
    }

    std::cout << niceStrings << "\n";
    std::cout << niceStrings2 << "\n";
}

