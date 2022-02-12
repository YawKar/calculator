#ifndef _EVALUATE_FUNCTIONS_HEADER
#define _EVALUATE_FUNCTIONS_HEADER
#include <complex.h>
#include "../AllNodes.h"

double complex evaluateVariableNode(VariableNode* variableNode);
double complex evaluateGraphNode(GraphNode* graphNode);
double complex evaluateConstantNode(ConstantNode* constantNode);
double complex evaluateFunctionNode(FunctionNode* functionNode);
double complex evaluateNumberNode(NumberNode* numberNode);
double complex evaluateOperatorNode(OperatorNode* operatorNode);

#endif