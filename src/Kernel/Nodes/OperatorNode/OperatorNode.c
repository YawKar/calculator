#include "OperatorNode.h"
#include <stdlib.h>

OperatorNode* newOperatorNode() {
    OperatorNode* node = (OperatorNode*)malloc(sizeof(OperatorNode));
    node->operands = newPointerContainer();
    node->type = OPERTYPE_NULL;
    return node;
}