#include "VariableNode.h"
#include <stdlib.h>

VariableNode* newVariableNode() {
    VariableNode* node = (VariableNode*)malloc(sizeof(VariableNode));
    node->operands = newPointerContainer();
    return node;
}