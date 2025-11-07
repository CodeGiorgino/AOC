#include <iostream>
#include <fstream>
#include <print>

template< class... Args >
void eprintln(std::format_string<Args...> fmt, Args&&... args) {
    std::print(std::cerr, "\033[1;31m""Error: ""\033[0m");
    std::println(std::cerr, fmt, args...);
}

void solution_1() {
    /* Input chars mapping:
     *   '(' up one floor
     *   ')' down one floor
     * */

    std::ifstream stream("input-1.txt");
    if (!stream) {
        eprintln("Cannot open input file.");
        return;
    }

    auto solution = 0;
    for (int buf; (buf = stream.get()) != EOF; ) {
        const auto ch = static_cast<char>(buf);
        switch (ch) {
            case '(':
                solution++;
                break;
            case ')':
                solution--;
                break;
        }
    }
    std::println("Solution 1: {}", solution);
}

void solution_2() {
}

int main(void) {
    solution_1();
    solution_2();
    return 0;
}
