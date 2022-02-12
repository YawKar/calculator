#include "../../../PointerContainer/PointerContainer.h"
#include "FunctionNode.h"
#include <stdlib.h>

FunctionNode* newFunctionNode() {
    FunctionNode* node = (FunctionNode*)malloc(sizeof(FunctionNode));
    node->operands = newPointerContainer();
    node->type = FUNCTION_NULL;
    return node;
}