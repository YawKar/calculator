#include "EvaluateFunctions.h"
#include <math.h>
#include <stdio.h>

double complex evaluateVariableNode(VariableNode* variableNode) {
    return evaluateGraphNode((GraphNode*)variableNode->operands->content[0]);
}

double complex evaluateGraphNode(GraphNode* graphNode) {
    switch (graphNode->type) {
        case NODETYPE_CONSTANT:
            return evaluateConstantNode((ConstantNode*)graphNode->node);
        case NODETYPE_FUNCTION:
            return evaluateFunctionNode((FunctionNode*)graphNode->node);
        case NODETYPE_NUMBER:
            return evaluateNumberNode((NumberNode*)graphNode->node);
        case NODETYPE_OPERATOR:
            return evaluateOperatorNode((OperatorNode*)graphNode->node);
        case NODETYPE_VARIABLE:
            return evaluateVariableNode((VariableNode*)graphNode->node);
    }
    return 0;
}

double complex evaluateConstantNode(ConstantNode* constantNode) {
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

double complex evaluateFunctionNode(FunctionNode* functionNode) {
    switch (functionNode->type) {
        case FUNCTION_ABS:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cabs(evaluateGraphNode(operand));
            }
        case FUNCTION_COS:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return ccos(evaluateGraphNode(operand));
            }
        case FUNCTION_CTG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return 1.0 / ctan(evaluateGraphNode(operand));
            }
        case FUNCTION_EXP:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cexp(evaluateGraphNode(operand));
            }
        case FUNCTION_IMAG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cimag(evaluateGraphNode(operand));
            }
        case FUNCTION_LN:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return clog(evaluateGraphNode(operand));
            }
        case FUNCTION_LOG:
            {
                GraphNode* base = (GraphNode*)functionNode->operands->content[0];
                GraphNode* operand = (GraphNode*)functionNode->operands->content[1];
                return logWithBase(evaluateGraphNode(base), evaluateGraphNode(operand));
            }
        case FUNCTION_MAG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return cabs(evaluateGraphNode(operand));
            }
        case FUNCTION_PHASE:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                double complex res = evaluateGraphNode(operand);
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
                return cpow(evaluateGraphNode(base), evaluateGraphNode(power));
            }
        case FUNCTION_REAL:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return creal(evaluateGraphNode(operand));
            }
        case FUNCTION_SIN:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return csin(evaluateGraphNode(operand));
            }
        case FUNCTION_SQRT:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return csqrt(evaluateGraphNode(operand));
            }
        case FUNCTION_TG:
            {
                GraphNode* operand = (GraphNode*)functionNode->operands->content[0];
                return ctan(evaluateGraphNode(operand));
            }
    }
    return 0;
}

double complex evaluateNumberNode(NumberNode* numberNode) {
    return numberNode->number;
}

double complex evaluateOperatorNode(OperatorNode* operatorNode) {
    GraphNode* left = (GraphNode*)operatorNode->operands->content[0];
    GraphNode* right = (GraphNode*)operatorNode->operands->content[1];
    switch (operatorNode->type) {
        case OPERTYPE_PLUS:
            return evaluateGraphNode(left) + evaluateGraphNode(right);
        case OPERTYPE_POW:
            return cpow(evaluateGraphNode(left), evaluateGraphNode(right));
        case OPERTYPE_DIV:
            return evaluateGraphNode(left) / evaluateGraphNode(right);
        case OPERTYPE_MINUS:
            return evaluateGraphNode(left) - evaluateGraphNode(right);
        case OPERTYPE_MULT:
            return evaluateGraphNode(left) * evaluateGraphNode(right);
    }
    return 0;
}