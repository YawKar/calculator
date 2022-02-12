#ifndef _FUNCTION_NODE_HEADER
#define _FUNCTION_NODE_HEADER
#include "../../../PointerContainer/PointerContainer.h"
#include "../../FunctionType.h"

struct FunctionNode {
    FunctionType type;
    PointerContainer* operands;
};
typedef struct FunctionNode FunctionNode;

FunctionNode* newFunctionNode();

#endif