#include "ConstantType.h"

int globalGetConstantTypeNumber() {
    return 2;
}
char* globalGetConstantByIndex(int index) {
    char* constants[2] = {
        "PI",
        "e"
    };
    return constants[index];
}