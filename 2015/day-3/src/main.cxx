#include <fstream>
#include <iostream>
#include <print>
#include <set>
#include <utility>

template<class ...Args>
void eprintln(std::format_string<Args...> fmt, Args&&... args) {
    std::print(std::cerr, "\033[1;31m""Error: ""\033[0m");
    std::println(std::cerr, fmt, args...);
}

void solution_1() {
    /* Input mappings:
     *   '^' one to the north
     *   'v' one to the south
     *   '>' one to the east
     *   '<' one to the west
     *
     * Input example:
     *   ^>v<
     * */

    std::ifstream stream("input-1.txt");
    if (!stream) {
        eprintln("Cannot open input file.");
        return;
    }

    int x = 0,
        y = 0;
    std::set<std::pair<int, int>> housesList = { { x, y } };
    for (int buf; (buf = stream.get()) != EOF; ) {
        const auto ch = static_cast<char>(buf);
        if (ch == '\n') continue;
        else if (ch == '^') y--;
        else if (ch == 'v') y++;
        else if (ch == '>') x++;
        else if (ch == '<') x--;
        else {
            eprintln("Invalid direction found: {:?}", ch);
            return;
        }
        housesList.insert({ x, y });
    }
    std::println("Solution 1: {}", housesList.size());
}

void solution_2() {
}

int main(void) {
    solution_1();
    solution_2();
    return 0;
}
