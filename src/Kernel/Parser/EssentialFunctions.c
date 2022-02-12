#include "EssentialFunctions.h"
#include "../OperatorType.h"
#include "../ConstantType.h"
#include "../FunctionType.h"
#include "../../StringFunctions/StringFunctions.h"
#include <string.h>

int countEndsBrackets(char* expression, int leftBorder, int rightBorder) {
    int endsBracketsCounter = 0;
    while (rightBorder - leftBorder - 2 * endsBracketsCounter > 1) {
        if (isExpressionBracketed(expression, leftBorder + endsBracketsCounter, rightBorder - endsBracketsCounter))
            ++endsBracketsCounter;
        else
            break;
    }
    return endsBracketsCounter;
}

int isOperator(char ch) {
    for (int operatorIndex = 0; operatorIndex < globalGetOperatorTypeNumber(); ++operatorIndex) {
        if (globalGetOperatorByIndex(operatorIndex) == ch)
            return 1;
    }
    return 0;
}

int isExpressionBracketed(char* expression, int leftBorder, int rightBorder) {
    if (expression[leftBorder] != '(' || expression[rightBorder - 1] != ')')
        return 0;
    int minLevelWithOperator = -1;
    int currentLevel = 0;
    for (int i = leftBorder; i < rightBorder; ++i) {
        if (isOperator(expression[i])) {
            if (minLevelWithOperator == -1)
                minLevelWithOperator = currentLevel;
            else if (minLevelWithOperator > currentLevel)
                minLevelWithOperator = currentLevel;
        }
        else if (expression[i] == '(') {
            ++currentLevel;
        }
        else if (expression[i] == ')') {
            --currentLevel;
        }
    }
    return minLevelWithOperator != 0;
}


// CHECKS

int hasOperatorOnTop(char* expression, int leftBorder, int rightBorder) {
    int currentLevel = 0;
    for (int i = leftBorder; i < rightBorder; ++i) {
        if (expression[i] == '(') {
            ++currentLevel;
            continue;
        }
        if (expression[i] == ')') {
            --currentLevel;
            continue;
        }
        if (currentLevel != 0)
            continue;
        for (int j = 0; j < globalGetOperatorTypeNumber(); ++j) {
            if (expression[i] == globalGetOperatorByIndex(j))
                return 1;
        }
    }
    return 0;
}

int hasNumberOnTop(char* expression, int leftBorder, int rightBorder) {
    int countDots = 0;
    int startIndex = leftBorder;
    while (expression[startIndex] == '-' || expression[startIndex] == '+')
        ++startIndex;
    for (int i = startIndex; i < rightBorder; ++i) {
        if (expression[i] == '.')
            ++countDots;
        else if (!((expression[i] >= '0' && expression[i] <= '9') || expression[i] == 'i')) {
            return 0;
        }
    }
    return countDots < 2;
}

int hasConstantOnTop(char* expression, int leftBorder, int rightBorder) {
    for (int constantIndex = 0; constantIndex < globalGetConstantTypeNumber(); ++constantIndex) {
        int constantLen = strlen(globalGetConstantByIndex(constantIndex));
        if (constantLen != rightBorder - leftBorder)
            continue;
        int areEqual = 1;
        for (int i = 0; i < constantLen; ++i) {
            areEqual &= globalGetConstantByIndex(constantIndex)[i] == expression[leftBorder + i];
        }
        if (areEqual)
            return 1;
    }
    return 0;
}

int hasFunctionOnTop(char* expression, int leftBorder, int rightBorder) {
    int openBracketIndex = -1;
    for (int i = leftBorder; i < rightBorder; ++i) {
        if (expression[i] == '(') {
            openBracketIndex = i;
            break;
        }
    }
    if (openBracketIndex == -1)
        return 0;
    for (int stdFunctionIndex = 0; stdFunctionIndex < globalGetFunctionTypeNumber(); ++stdFunctionIndex) {
        int stdFunctionLen = strlen(globalGetFunctionByIndex(stdFunctionIndex));
        if (stdFunctionLen != openBracketIndex - leftBorder)
            continue;
        int areEqual = 1;
        for (int j = 0; j < stdFunctionLen; ++j)
            if (globalGetFunctionByIndex(stdFunctionIndex)[j] != expression[leftBorder + j]) {
                areEqual = 0;
                break;
            }
        if (areEqual) {
            return 1;
        }
    }
    return 0;
}


// Getters

int getHighestOperatorIndex(char* expression, int leftBorder, int rightBorder) {
    int currentLevel = 0;
    int highestOperatorIndex = -1;
    int highestOperator = -1;
    for (int i = leftBorder; i < rightBorder; ++i) {
        if (expression[i] == '(') {
            ++currentLevel;
            continue;
        }
        if (expression[i] == ')') {
            --currentLevel;
            continue;
        }
        if (currentLevel != 0)
            continue;
        for (int j = 0; j < globalGetOperatorTypeNumber(); ++j) {
            if (expression[i] == globalGetOperatorByIndex(j)) {
                if (j > highestOperator) {
                    highestOperator = j;
                    highestOperatorIndex = i;
                }
            }
        }
    }
    return highestOperatorIndex;
}

OperatorType getOperatorType(char ch) {
    for (int operatorIndex = 0; operatorIndex < globalGetOperatorTypeNumber(); ++operatorIndex) {
        if (globalGetOperatorByIndex(operatorIndex) == ch) {
            return (OperatorType)operatorIndex;
        }
    }
    return OPERTYPE_NULL;
}

ConstantType getConstantType(char* expression, int leftBorder, int rightBorder) {
    for (int constantIndex = 0; constantIndex < globalGetConstantTypeNumber(); ++constantIndex) {
        int constantLen = strlen(globalGetConstantByIndex(constantIndex));
        if (constantLen != rightBorder - leftBorder)
            continue;
        int areEqual = 1;
        for (int j = 0; j < constantLen; ++j) {
            areEqual &= globalGetConstantByIndex(constantIndex)[j] == expression[leftBorder + j];
        }
        if (areEqual) {
            return (ConstantType)constantIndex;
        }
    }
    return CONSTANT_NULL;
}

FunctionType getFunctionType(char* expression, int leftBorder, int rightBorder) {
    int openBracketIndex = -1;
    for (int i = leftBorder; i < rightBorder; ++i) {
        if (expression[i] == '(') {
            openBracketIndex = i;
            break;
        }
    }
    if (openBracketIndex == -1)
        return 0;
    for (int FunctionIndex = 0; FunctionIndex < globalGetFunctionTypeNumber(); ++FunctionIndex) {
        int FunctionLen = strlen(globalGetFunctionByIndex(FunctionIndex));
        if (FunctionLen != openBracketIndex - leftBorder)
            continue;
        int areEqual = 1;
        for (int j = 0; j < FunctionLen; ++j)
            if (globalGetFunctionByIndex(FunctionIndex)[j] != expression[leftBorder + j]) {
                areEqual = 0;
                break;
            }
        if (areEqual) {
            return (FunctionType)FunctionIndex;
        }
    }
    return FUNCTION_NULL;
}