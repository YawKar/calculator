#ifndef _CONSTANT_TYPE_HEADER
#define _CONSTANT_TYPE_HEADER

enum ConstantType {
    CONSTANT_PI,        // PI   (3.14159...)
    CONSTANT_EULER,     // e    (2.71....)
    CONSTANT_NULL       // Not assigned constant
};
typedef enum ConstantType ConstantType;

int globalGetConstantTypeNumber();
char* globalGetConstantByIndex(int index);


#endif