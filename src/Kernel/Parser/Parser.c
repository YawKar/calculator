#include "Parser.h"
#include "EssentialFunctions.h"
#include "../AllNodes.h"
#include "../../StringFunctions/StringFunctions.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void processOperator(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    root->type = NODETYPE_OPERATOR;
    int highestOperatorIndex = getHighestOperatorIndex(expression, leftBorder, rightBorder);
    OperatorType highestOperator = getOperatorType(expression[highestOperatorIndex]);
    OperatorNode* operatorNode = newOperatorNode();
    root->node = (void*)operatorNode;
    operatorNode->type = highestOperator;
    GraphNode* leftOperand = newGraphNode();
    GraphNode* rightOperand = newGraphNode();
    containerPush(operatorNode->operands, (void*)leftOperand);
    containerPush(operatorNode->operands, (void*)rightOperand);
    parseExpression(leftOperand, expression, leftBorder, highestOperatorIndex, vTable);
    parseExpression(rightOperand, expression, highestOperatorIndex + 1, rightBorder, vTable);
}

void processNumber(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    root->type = NODETYPE_NUMBER;
    double complex parsedNumber = parseNumber(expression, leftBorder, rightBorder);
    NumberNode* numberNode = newNumberNode();
    root->node = (void*)numberNode;
    numberNode->number = parsedNumber;
}

void processConstant(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    root->type = NODETYPE_CONSTANT;
    ConstantNode* constantNode = newConstantNode();
    root->node = (void*)constantNode;
    constantNode->type = getConstantType(expression, leftBorder, rightBorder);
}

void processFunction(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    root->type = NODETYPE_FUNCTION;
    FunctionNode* functionNode = newFunctionNode();
    root->node = (void*)functionNode;
    functionNode->operands = newPointerContainer();
    functionNode->type = getFunctionType(expression, leftBorder, rightBorder);
    parseOperands(expression, leftBorder, rightBorder, functionNode->operands, vTable);
}

void processVariable(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    root->type = NODETYPE_VARIABLE;
    char* variableName = (char*)malloc(sizeof(char) * (rightBorder - leftBorder + 1));
    for (int i = leftBorder; i < rightBorder; ++i) {
        variableName[i - leftBorder] = expression[i];
    }
    variableName[rightBorder - leftBorder] = '\0';
    if (vTable->containVariable(vTable, variableName)) {
        root->node = vTable->getVariableNode(vTable, variableName);
    }
    else {
        vTable->addVariableName(vTable, variableName);
        VariableNode* variableNode = newVariableNode();
        variableNode->name = copyString(variableName);
        vTable->assignVariableNode(vTable, variableName, variableNode);
        root->node = (void*)variableNode;
    }
}


void parseExpression(GraphNode* root, char* expression, int leftBorder, int rightBorder, VariablesTable* vTable) {
    if (isExpressionBracketed(expression, leftBorder, rightBorder)) {
		int endsBracketsNumber = countEndsBrackets(expression, leftBorder, rightBorder);
		leftBorder += endsBracketsNumber;
		rightBorder -= endsBracketsNumber;
	}
    if (hasNumberOnTop(expression, leftBorder, rightBorder)) {
        processNumber(root, expression, leftBorder, rightBorder, vTable);
    } else if (hasConstantOnTop(expression, leftBorder, rightBorder)) {
        processConstant(root, expression, leftBorder, rightBorder, vTable);
    } else if (hasFunctionOnTop(expression, leftBorder, rightBorder)) {
        processFunction(root, expression, leftBorder, rightBorder, vTable);
    } else if (hasOperatorOnTop(expression, leftBorder, rightBorder)) {
        processOperator(root, expression, leftBorder, rightBorder, vTable);
    } else { // has variable on top
        processVariable(root, expression, leftBorder, rightBorder, vTable);
    }
}

void parseOperands(char* expression, int leftBorder, int rightBorder, PointerContainer* operands, VariablesTable* vTable) {
    int openBracketIndex = -1;
	for (int i = leftBorder; i < rightBorder; ++i) {
		if (expression[i] == '(') {
			openBracketIndex = i;
			break;
		}
	}
	int lastCommaIndex = openBracketIndex;
	int currentLevel = 0;
	for (int i = openBracketIndex + 1; i < rightBorder - 1; ++i) {
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
		if (expression[i] == ',') {
			// Found argument
			GraphNode* newOperand = newGraphNode();
            containerPush(operands, (void*)newOperand);
			parseExpression(newOperand, expression, lastCommaIndex + 1, i, vTable);
			lastCommaIndex = i;
		}
	}
	// Last argument
	GraphNode* newOperand = newGraphNode();
	containerPush(operands, (void*)newOperand);
	parseExpression(newOperand, expression, lastCommaIndex + 1, rightBorder - 1, vTable);
}

double complex parseNumber(char* expression, int leftBorder, int rightBorder) {
    int numberSign = 0;
    int startIndex = leftBorder;
    while (expression[startIndex] == '-' || expression[startIndex] == '+') {
        numberSign ^= expression[startIndex] == '-';
        ++startIndex;
    }
    double complex parsedNumber = 0;
    int dotIndex = -1;
    for (int i = startIndex; i < rightBorder; ++i) {
        if (expression[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    int isComplex = expression[rightBorder - 1] == 'i';
    if (dotIndex == -1) {
        for (int i = startIndex; i < rightBorder - isComplex; ++i)
            parsedNumber += pow(10L, (double)rightBorder - isComplex - i - 1) * ((double)expression[i] - '0');
    } else {
        for (int i = startIndex; i < dotIndex; ++i)
            parsedNumber += pow(10L, (double)dotIndex - i - 1) * ((double)expression[i] - '0');
        for (int i = dotIndex + 1; i < rightBorder - isComplex; ++i)
            parsedNumber += pow(10L, (double)dotIndex - i) * ((double)expression[i] - '0');
    }
    if (rightBorder - startIndex == 1 && expression[startIndex] == 'i') {
        parsedNumber = 1*I;
    } else if (isComplex) {
        parsedNumber = creal(parsedNumber) * I;
    }
    if (numberSign == 1)
        parsedNumber *= -1.0L;
    return parsedNumber;
}