#include "GraphNode.h"
#include "../NodeType.h"
#include <stdlib.h>

GraphNode* newGraphNode() {
    GraphNode* grNode = (GraphNode*)malloc(sizeof(GraphNode));
    grNode->node = NULL;
    grNode->type = NODETYPE_NULL;
    return grNode;
}
