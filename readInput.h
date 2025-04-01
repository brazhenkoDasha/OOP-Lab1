#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <iostream>
#include <limits>

template <typename T>
T readInput() {
    T value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a correct value: ";
        } else {
            break;
        }
    }
    return value;
}

#endif