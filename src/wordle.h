#ifndef DATA_STRUCTURES_AND_ALGORITHM_WORDLE_H

#include <string>
#include <unordered_set>
#include <random>

class Wordle {
public:
    Wordle();

    void run();
    void guess();

private:
    static const char *word_list[];
    static constexpr int word_list_size = 2315;
    int m_select;
    std::default_random_engine e;
    std::uniform_int_distribution<int> d;

    std::unordered_set<char> m_used_letters;

    bool guess(const std::string &word);
    inline int select();
};

#define DATA_STRUCTURES_AND_ALGORITHM_WORDLE_H

#endif //DATA_STRUCTURES_AND_ALGORITHM_WORDLE_H
