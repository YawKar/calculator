#ifndef _UNARY_NODE_HEADER
#define _UNARY_NODE_HEADER
#include "../../../PointerContainer/PointerContainer.h"
#include "../../UnaryType.h"

typedef struct UnaryNode UnaryNode;
struct UnaryNode {
    UnaryType type;
    PointerContainer* pointerContainer;
};

UnaryNode* newUnaryNode();

#endif