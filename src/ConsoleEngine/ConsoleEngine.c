#include <stdio.h>
#include "ConsoleEngine.h"
#include "../Logger/Logger.h"
#include "CommandLineInterface.h"
#include "LineArgs/LineArgs.h"
#include "../Kernel/VariablesTable/VariablesTable.h"

void runConsoleEngine(Logger* logger) {
    logger->addRecord(logger, "Entered the runConsoleEngine()");
    int exit = 0;
    char* calculatorTitle = "(calc)";
    VariablesTable* vTable = newVariablesTable();
    logger->addRecord(logger, "Entered the main while(!exit) cycle");
    while (!exit) {
        printf("%s ", calculatorTitle);
        char* inputLine = getInputLine();
        logger->addRecord(logger, "Got user's input line (raw):");
        logger->addRecord(logger, inputLine);
        LineArgs* lineArgs = parseLineArgs(inputLine);
        exit = performCommand(lineArgs, vTable, logger);
    }
    logger->addRecord(logger, "Ended the main while(!exit) cycle");
}
