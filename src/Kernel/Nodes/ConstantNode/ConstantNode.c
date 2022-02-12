#include "ConstantNode.h"
#include <stdlib.h>

ConstantNode* newConstantNode() {
    ConstantNode* node = (ConstantNode*)malloc(sizeof(ConstantNode));
    node->type = CONSTANT_NULL;
    return node;
}