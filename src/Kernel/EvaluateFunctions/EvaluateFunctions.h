#ifndef _EVALUATE_FUNCTIONS_HEADER
#define _EVALUATE_FUNCTIONS_HEADER
#include <complex.h>
#include "../AllNodes.h"
#include "../VariablesTable/VariablesTable.h"

double complex evaluateVariableNode(VariableNode* variableNode, VariablesTable* variablesTable);
double complex evaluateGraphNode(GraphNode* graphNode, VariablesTable* variablesTable);
double complex evaluateConstantNode(ConstantNode* constantNode, VariablesTable* variablesTable);
double complex evaluateFunctionNode(FunctionNode* functionNode, VariablesTable* variablesTable);
double complex evaluateNumberNode(NumberNode* numberNode, VariablesTable* variablesTable);
double complex evaluateOperatorNode(OperatorNode* operatorNode, VariablesTable* variablesTable);
double complex evaluateUnaryNode(UnaryNode* unaryNode, VariablesTable* variablesTable);

#endif