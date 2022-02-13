#ifndef _UNARY_TYPE_HEADER
#define _UNARY_TYPE_HEADER

typedef enum UnaryType UnaryType;
enum UnaryType {
    UNARY_PLUS,         //  +
    UNARY_MINUS,        //  -
    UNARY_NULL          // Not assigned
};

int globalGetUnaryTypeNumber();
char globalGetUnaryByIndex(int index);

#endif