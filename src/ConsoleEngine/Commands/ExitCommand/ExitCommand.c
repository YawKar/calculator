#include "ExitCommand.h"
#include <stdio.h>

int performExitCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger) {
    if (lineArgs->argsNumber != 1) {
        printf("Command 'exit' doesn't have any arguments, but %d were provided\n", lineArgs->argsNumber - 1);
        logger->addRecord(logger, "'exit': incorrect amount of arguments.");
        return 0;
    }
    return 1;
}