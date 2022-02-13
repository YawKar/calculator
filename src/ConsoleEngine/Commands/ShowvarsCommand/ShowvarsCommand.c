#include "ShowvarsCommand.h"
#include <stdio.h>
#include "../../../Kernel/AllNodes.h"

int performShowvarsCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream) {
    fprintf(outputStream, "Variables Table:\n");
    for (int i = 0; i < vTable->size(vTable); ++i) {
        fprintf(outputStream, "%d: '%s' '%s'\n", i, (char*)vTable->variableNames->content[i], 
                ((VariableNode*)vTable->getVariableNode(vTable, (char*)vTable->variableNames->content[i]))->operands->size == 0 ?
                "N/A" : "OK");
    }
    return 0;
}