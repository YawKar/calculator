#ifndef _OPERATOR_NODE_HEADER
#define _OPERATOR_NODE_HEADER
#include "../../../PointerContainer/PointerContainer.h"
#include "../../OperatorType.h"

struct OperatorNode {
    OperatorType type;
    PointerContainer* operands;
};
typedef struct OperatorNode OperatorNode;

OperatorNode* newOperatorNode();

#endif