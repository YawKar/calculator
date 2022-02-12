#ifndef _OPERATOR_TYPE_HEADER
#define _OPERATOR_TYPE_HEADER

enum OperatorType {
    OPERTYPE_PLUS,      // +
    OPERTYPE_MINUS,     // -
    OPERTYPE_MULT,      // *
    OPERTYPE_DIV,       // /
    OPERTYPE_POW,       // ^
    OPERTYPE_NULL       // Not assigned operator
};
typedef enum OperatorType OperatorType;

int globalGetOperatorTypeNumber();
char globalGetOperatorByIndex(int index);

#endif