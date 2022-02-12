#ifndef _GRAPH_NODE_HEADER
#define _GRAPH_NODE_HEADER
#include "../NodeType.h"

struct GraphNode {
    NodeType type;
    void* node;
};
typedef struct GraphNode GraphNode;
GraphNode* newGraphNode();

#endif
