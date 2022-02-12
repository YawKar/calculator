#include "NumberNode.h"
#include <stdlib.h>

NumberNode* newNumberNode() {
    NumberNode* node = (NumberNode*)malloc(sizeof(NumberNode));
    node->number = 0 + 0 * I;
    return node;
}