#ifndef _CONSTANT_NODE_HEADER
#define _CONSTANT_NODE_HEADER
#include "../../ConstantType.h"

struct ConstantNode {
    ConstantType type;
};

typedef struct ConstantNode ConstantNode;

ConstantNode* newConstantNode();

#endif