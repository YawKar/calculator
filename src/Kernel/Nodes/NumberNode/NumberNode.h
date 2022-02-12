#ifndef _NUMBER_NODE_HEADER
#define _NUMBER_NODE_HEADER
#include <complex.h>

struct NumberNode {
    double _Complex number;
};
typedef struct NumberNode NumberNode;

NumberNode* newNumberNode();

#endif