#include "OperatorType.h"

int globalGetOperatorTypeNumber() {
    return 6;
}

char globalGetOperatorByIndex(int index) {
    char* operators = "+-*/^";
    if (index < 0 || index > globalGetOperatorTypeNumber())
        return '_';
    return operators[index];
}