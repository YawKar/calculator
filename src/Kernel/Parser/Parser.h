#ifndef _PARSER_HEADER
#define _PARSER_HEADER
#include "../GraphNode/GraphNode.h"
#include "../VariablesTable/VariablesTable.h"
#include "../../PointerContainer/PointerContainer.h"
#include <complex.h>

void parseExpression(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable);
void parseOperands(char* expression, int leftBorder, int rightBorder, PointerContainer* operands, VariablesTable* vTable);
double complex parseNumber(char* expression, int leftBorder, int rightBorder);

#endif