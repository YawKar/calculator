#include "FunctionType.h"

int globalGetFunctionTypeNumber() {
    return 14;
}
char* globalGetFunctionByIndex(int index) {
    char* functions[14] = {
        "cos",
        "sin",
        "tg",
        "ctg",
        "log",
        "ln",
        "sqrt",
        "pow",
        "abs",
        "exp",
        "real",
        "imag",
        "mag",
        "phase"
    };
    return functions[index];
}