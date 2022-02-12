#include "InfoCommand.h"
#include <stdio.h>

int performInfoCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger) {
    printf("Engine status:\n");
    printf("+ Variables Total: %d\n", vTable->size(vTable));
    return 0;
}