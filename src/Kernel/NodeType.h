#ifndef _NODETYPE_HEADER
#define _NODETYPE_HEADER

enum NodeType {
    NODETYPE_NULL,      // Not assigned node
    NODETYPE_NUMBER,    // Number node
    NODETYPE_FUNCTION,  // Function node
    NODETYPE_OPERATOR,  // Operator node
    NODETYPE_CONSTANT,  // Constant node
    NODETYPE_VARIABLE   // Variable node
};

typedef enum NodeType NodeType;

#endif
