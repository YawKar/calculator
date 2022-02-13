#include "OperatorType.h"

int globalGetOperatorTypeNumber() {
    return 5;
}

char globalGetOperatorByIndex(int index) {
    char* operators = "+-*/^";
    if (index < 0 || index >= globalGetOperatorTypeNumber())
        return '_';
    return operators[index];
}