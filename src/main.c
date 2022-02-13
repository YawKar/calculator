#include <stdio.h>
#include "ConsoleEngine/ConsoleEngine.h"
#include "Logger/Logger.h"
#include "AutoMode/AutoMode.h"

int main(int argc, char* argv[]) {
    Logger* logger = newLogger();
    logger->addRecord(logger, "Logger inited");
    if (argc == 1) {
        logger->addRecord(logger, "No arguments were provided in command line");
        logger->addRecord(logger, "Switched to interactive mode");
        logger->addRecord(logger, "Running runConsoleEngine()");
        runConsoleEngine(logger);
        logger->addRecord(logger, "Returned from runConsoleEngine()");
    } else {
        logger->addRecord(logger, "Found arguments in command line");
        logger->addRecord(logger, "Switched to auto mode");
        logger->addRecord(logger, "Running runAutoMode()");
        runAutoMode(argc, argv, logger);
        logger->addRecord(logger, "Returned from runAutoMode()");
    }
    logger->printRecords(logger);
    return 0;
}
