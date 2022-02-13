#include "HelpCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../../FileFunctions/FileFunctions.h"

int performHelpCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream) {
    if (lineArgs->argsNumber != 1) {
        fprintf(outputStream, "Command 'help' doesn't have any arguments, but %d were provided\n", lineArgs->argsNumber - 1);
        logger->addRecord(logger, "'help': incorrect amount of arguments.");
        return 0;
    }
    FILE* helpMenuFile = fopen("helpMenuText.txt", "r");
    char* helpMenu = readContentOfFile(helpMenuFile);
    fclose(helpMenuFile);
    fprintf(outputStream, "%s\n", helpMenu);
    if (helpMenu)
        free(helpMenu);
    logger->addRecord(logger, "Printed help-menu");
    return 0;
}