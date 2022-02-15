#include "EvaluateFunctions.h"
#include "../VariablesTable/VariablesTable.h"
#include <math.h>
#include <stdio.h>

double complex evaluateVariableNode(VariableNode* variableNode, VariablesTable* vTable) {
    return evaluateGraphNode((GraphNode*)variableNode->operands->content[0], vTable);
}

double complex evaluateGraphNode(GraphNode* graphNode, VariablesTable* vTable) {
    switch (graphNode->type) {
        case NODETYPE_CONSTANT:
            return evaluateConstantNode((ConstantNode*)graphNode->node, vTable);
        case NODETYPE_FUNCTION:
            return evaluateFunctionNode((FunctionNode*)graphNode->node, vTable);
        case NODETYPE_NUMBER:
            return evaluateNumberNode((NumberNode*)graphNode->node, vTable);
        case NODETYPE_OPERATOR:
            return evaluateOperatorNode((OperatorNode*)graphNode->node, vTable);
        case NODETYPE_VARIABLE:
            return evaluateVariableNode((VariableNode*)graphNode->node, vTable);
        case NODETYPE_UNARY:
            return evaluateUnaryNode((UnaryNode*)graphNode->node, vTable);
    }
    return 0;
}

double complex evaluateUnaryNode(UnaryNode* unaryNode, VariablesTable* vTable) {
    switch (unaryNode->type) {
        case UNARY_MINUS:
            return (-1.0L) * evaluateGraphNode((GraphNode*)unaryNode->pointerContainer->content[0], vTable);
        case UNARY_PLUS:
            return evaluateGraphNode((GraphNode*)unaryNode->pointerContainer->content[0], vTable);
    }
    return 0;
}

double complex evaluateConstantNode(ConstantNode* constantNode, VariablesTable* vTable) {
    switch (constantNode->type) {
        case CONSTANT_EULER:
            return 2.71828182845904523536;
        case CONSTANT_PI:
            return 3.14159265358979323846;
    }
    return 0;
}

double complex logWithBase(double complex base, double complex x) {
    return clog(x) / clog(base);
}

double complex evaluateFunctionNode(FunctionNode* functionNode, VariablesTable* vTable) {
    switch (functionNode->type) {
        case FUNCTION_ABS:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cabs(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_COS:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return ccos(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_CTG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return 1.0 / ctan(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_EXP:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cexp(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_IMAG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cimag(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_LN:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return clog(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_LOG:
            {
                GraphNode* base = (GraphNode*)functionNode->operands->content[0];
                GraphNode* operand = (GraphNode*)functionNode->operands->content[1];
                return logWithBase(evaluateGraphNode(base, vTable), evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_MAG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cabs(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_PHASE:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                double complex res = evaluateGraphNode(operand, vTable);
                double complex w = 0;
                if (creal(res) < 0 && cimag(res) >= 0)
                    w = 3.14159265358979323846;
                else if (creal(res) < 0 && cimag(res) < 0)
                    w = -3.14159265358979323846;
                return catan(cimag(res) / creal(res)) + w;
            }
        case FUNCTION_POW:
            {
                GraphNode* base = (GraphNode*)functionNode->operands->content[0];
                GraphNode* power = (GraphNode*)functionNode->operands->content[1];
                return cpow(evaluateGraphNode(base, vTable), evaluateGraphNode(power, vTable));
            }
        case FUNCTION_REAL:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return creal(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_SIN:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return csin(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_SQRT:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return csqrt(evaluateGraphNode(operand, vTable));
            }
        case FUNCTION_TG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return ctan(evaluateGraphNode(operand, vTable));
            }
    }
    return 0;
}

double complex evaluateNumberNode(NumberNode* numberNode, VariablesTable* vTable) {
    return numberNode->number;
}

double complex evaluateOperatorNode(OperatorNode* operatorNode, VariablesTable* vTable) {
    GraphNode* left = (GraphNode*)operatorNode->operands->content[0];
    GraphNode* right = (GraphNode*)operatorNode->operands->content[1];
    switch (operatorNode->type) {
        case OPERTYPE_PLUS:
            return evaluateGraphNode(left, vTable) + evaluateGraphNode(right, vTable);
        case OPERTYPE_POW:
            return cpow(evaluateGraphNode(left, vTable), evaluateGraphNode(right, vTable));
        case OPERTYPE_DIV:
            {
                double complex leftRes = evaluateGraphNode(left, vTable);
                double complex rightRes = evaluateGraphNode(right, vTable);
                return evaluateGraphNode(left, vTable) / evaluateGraphNode(right, vTable);
            }
        case OPERTYPE_MINUS:
            return evaluateGraphNode(left, vTable) - evaluateGraphNode(right, vTable);
        case OPERTYPE_MULT:
            return evaluateGraphNode(left, vTable) * evaluateGraphNode(right, vTable);
    }
    return 0;
}