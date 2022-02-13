#include "UnaryType.h"

int globalGetUnaryTypeNumber() {
    return 2;
}
char globalGetUnaryByIndex(int index) {
    char* unaries = "+-";
    if (index < 0 || index >= globalGetUnaryTypeNumber())
        return '_';
    return unaries[index];
}