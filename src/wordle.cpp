#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

#include "wordle.h"

Wordle::Wordle() : e(time(nullptr)) {
    select();
}

void Wordle::run() {

}

void Wordle::guess() {
    // receiving from keyboard and call overloading function.
    std::string input;
    for (int i = 0; i < 6;) {
        std::cin >> input;
        if (input.size() != 5) {
            printf("\r");
            continue;
        }
        if (guess(input)) {
            std::cout << "You win!" << std::endl;
            return;
        }
        ++i;
    }
    std::cout << "You lose!" << std::endl;
}

// judge whether the input is correct.
bool Wordle::guess(const std::string &word) {
    int right = 0;
    // printf("\e[0;31mhe\e[0;32mll\e[1;33mow");
    for (int i = 0; i < 5; ++i) {
        if (word[i] == word_list[m_select][i]) {
            printf("\e[0;32m%c", word[i]);
            ++right;
        } else if (m_used_letters.contains(word[i])) {
            // TODO: draw brown
            printf("\e[1;33m%c", word[i]);
        } else {
            // TODO: draw gray
            printf("\e[1;31m%c", word[i]);
        }
    }
    printf("\n");
    printf("\e[0m");
    return right == 5;
}

inline int Wordle::select() {
    m_select = d(e) % word_list_size;
    m_used_letters.clear();
    const char *p = word_list[m_select];
    while (*p != '\0')
        m_used_letters.insert(*p++);
    std::cout << word_list[m_select] << std::endl;
    return m_select;
}
