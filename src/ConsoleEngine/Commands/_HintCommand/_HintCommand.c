#include "_HintCommand.h"
#include <stdio.h>

void printHelpHint(Logger* logger, FILE* outputStream) {
    fprintf(outputStream, "Type 'help' to see available commands.\n");
    logger->addRecord(logger, "Printed help-hint");
}