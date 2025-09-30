#pragma once

int fibonacci_iterative(int sequence) {
    int current_number{0};
    int next_number{1};
    for (int i{0}; i < sequence; ++i) {
        int new_number = current_number + next_number;
        current_number = next_number;
        next_number = new_number;
    }
    return current_number;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0 || sequence == 1) {
        return sequence;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
