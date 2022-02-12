#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CommandLineInterface.h"
#include "../StringFunctions/StringFunctions.h"
#include "../Logger/Logger.h"
#include "LineArgs/LineArgs.h"

#include "Commands/SetCommand/SetCommand.h"
#include "Commands/ExitCommand/ExitCommand.h"
#include "Commands/HelpCommand/HelpCommand.h"
#include "Commands/_HintCommand/_HintCommand.h"
#include "Commands/ShowvarsCommand/ShowvarsCommand.h"
#include "Commands/InfoCommand/InfoCommand.h"
#include "Commands/EvaluateCommand/EvaluateCommand.h"

// Returns 1 if 'exit' command was entered.
int performCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger) {
    if (lineArgs->argsNumber == 0) {
        logger->addRecord(logger, "Empty lineArgs");
        printf("No commands were found.\n");
        printHelpHint(logger);
        return 0;
    }
    if (areStringsEqual(lineArgs->args[0], "help")) {
        return performHelpCommand(lineArgs, vTable, logger);
    } else if (areStringsEqual(lineArgs->args[0], "exit")) {
        return performExitCommand(lineArgs, vTable, logger);
    } else if (areStringsEqual(lineArgs->args[0], "set")) {
        return performSetCommand(lineArgs, vTable, logger);
    } else if (areStringsEqual(lineArgs->args[0], "showvars")) {
        return performShowvarsCommand(lineArgs, vTable, logger);
    } else if (areStringsEqual(lineArgs->args[0], "info")) {
        return performInfoCommand(lineArgs, vTable, logger);
    } else if (areStringsEqual(lineArgs->args[0], "evaluate")) {
        return performEvaluateCommand(lineArgs, vTable, logger);
    } else {
        // Default warning
        logger->addRecord(logger, "Unknown command was entered");
        printf("Unknown command '%s'.\n", lineArgs->args[0]);
        printHelpHint(logger);
        return 0;
    }
    return 0;
}

char* getInputLine() {
    char* line = NULL;
    int lineLength = 0;
    int curIndex = 0;
    char c = getchar();
    while (c != '\n') {
        if (curIndex == lineLength) {
            // Need to lengthen the line
            char* copyLine = (char*)calloc(lineLength * 2 + 1, sizeof(char));
            for (int index = 0; index < lineLength; ++index)
                copyLine[index] = line[index];
            lineLength = lineLength * 2 + 1;
            if (line)
                free(line);
            line = copyLine;
        }
        line[curIndex++] = c;
        c = getchar();
    }
    if (curIndex == lineLength) {
        char* copyLine = (char*)malloc(sizeof(char) * (lineLength + 1));
        for (int index = 0; index < lineLength; ++index)
            copyLine[index] = line[index];
        lineLength = lineLength + 1;
        if (line)
            free(line);
        line = copyLine;
    }
    line[curIndex++] = '\0';
    return line;
}
