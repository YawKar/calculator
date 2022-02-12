#ifndef _VARIABLE_NODE_HEADER
#define _VARIABLE_NODE_HEADER
#include "../../../PointerContainer/PointerContainer.h"

struct VariableNode {
    char* name;
    PointerContainer* operands;
};
typedef struct VariableNode VariableNode;

VariableNode* newVariableNode();

#endif