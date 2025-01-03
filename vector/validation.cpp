#include <iostream>
#include <limits>
#include "validation.h"
bool isInvalidInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}
bool isInteger(double value) {
    return value == static_cast<int>(value);
}
