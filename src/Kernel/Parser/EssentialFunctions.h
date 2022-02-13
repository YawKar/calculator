#ifndef _ESSENTIAL_FUNCTIONS_HEADER
#define _ESSENTIAL_FUNCTIONS_HEADER
#include "../AllNodes.h"


int isExpressionBracketed(char* expression, int leftBorder, int rightBorder);
int countEndsBrackets(char* expression, int leftBorder, int rightBorder);

// CHECKS
int hasOperatorOnTop(char* expression, int leftBorder, int rightBorder);
int hasNumberOnTop(char* expression, int leftBorder, int rightBorder);
int hasConstantOnTop(char* expression, int leftBorder, int rightBorder);
int hasFunctionOnTop(char* expression, int leftBorder, int rightBorder);
int hasUnaryOnTop(char* expression, int leftBorder, int rightBorder);

// Getters
int getHighestOperatorIndex(char* expression, int leftBorder, int rightBorder);
OperatorType getOperatorType(char ch);
ConstantType getConstantType(char* expression, int leftBorder, int rightBorder);
FunctionType getFunctionType(char* expression, int leftBorder, int rightBorder);
UnaryType getUnaryType(char* expression, int leftBorder, int rightBorder);

#endif