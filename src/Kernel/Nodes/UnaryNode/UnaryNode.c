#include "UnaryNode.h"
#include <stdlib.h>

UnaryNode* newUnaryNode() {
    UnaryNode* node = (UnaryNode*)malloc(sizeof(UnaryNode));
    node->pointerContainer = newPointerContainer();
    node->type = UNARY_NULL;
    return node;
}