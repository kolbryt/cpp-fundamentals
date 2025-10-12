#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;
    int termOfSequence{step};
    for (int i{count}; i > 0; --i) {
        sequence.push_back(termOfSequence);
        termOfSequence += step;
    }
    return sequence;
}
