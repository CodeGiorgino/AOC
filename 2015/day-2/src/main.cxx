#include <algorithm>
#include <fstream>
#include <iostream>
#include <print>
#include <vector>

template< class... Args >
void eprintln(std::format_string<Args...> fmt, Args&&... args) {
    std::print(std::cerr, "\033[1;31m""Error: ""\033[0m");
    std::println(std::cerr, fmt, args...);
}

void solution_1() {
    /* Input mappings:
     *   'l' length
     *   'w' width
     *   'h' height
     *
     * Surface area:
     *   2*l*w + 2*w*h + 2*h*l
     *
     * Solution:
     *   surfaceArea + smallestSideArea
     *
     * Input example:
     *   2x3x4
     * */

    std::ifstream stream("input-1.txt");
    if (!stream) {
        eprintln("Cannot open input file.");
        return;
    }

    auto solution = 0;
    for (std::string line; std::getline(stream, line); ) {
        auto buf = line;
        std::vector<int> sidesList{};
        for (size_t delim; (delim = buf.find("x")) != std::string::npos; ) {
            sidesList.push_back(std::stoi(buf.substr(0, delim)));
            buf = buf.substr(delim + 1);
        };
        sidesList.push_back(std::stoi(buf));
        std::ranges::sort(sidesList);
        if (sidesList.size() != 3) {
            eprintln("Unexpected shape found.");
            return;
        }
        solution += sidesList[0] * sidesList[1];
        for (auto i = 0; i < sidesList.size(); i++) {
            for (auto j = i + 1; j < sidesList.size(); j++) {
                solution += 2 * sidesList[i] * sidesList[j];
            }
        }
    };
    std::println("Solution 1: {}", solution);
}

void solution_2() {
    /* Solution:
     *   volume + smallestPerimeter
     * */

    std::ifstream stream("input-2.txt");
    if (!stream) {
        eprintln("Cannot open input file.");
        return;
    }

    auto solution = 0;
    for (std::string line; std::getline(stream, line); ) {
        auto buf = line;
        std::vector<int> sidesList{};
        for (size_t delim; (delim = buf.find("x")) != std::string::npos; ) {
            sidesList.push_back(std::stoi(buf.substr(0, delim)));
            buf = buf.substr(delim + 1);
        };
        sidesList.push_back(std::stoi(buf));
        std::ranges::sort(sidesList);
        if (sidesList.size() != 3) {
            eprintln("Unexpected shape found.");
            return;
        }
        solution += 2 * sidesList[0] + 2 * sidesList[1];
        solution += sidesList[0] * sidesList[1] * sidesList[2];
    };
    std::println("Solution 2: {}", solution);
}

int main(void) {
    solution_1();
    solution_2();
    return 0;
}
