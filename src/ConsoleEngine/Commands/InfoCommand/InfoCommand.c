#include "InfoCommand.h"
#include <stdio.h>

int performInfoCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream) {
    fprintf(outputStream, "Engine status:\n");
    fprintf(outputStream, "+ Variables Total: %d\n", vTable->size(vTable));
    return 0;
}