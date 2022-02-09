#include <stdio.h>
#include "ConsoleEngine/ConsoleEngine.h"
#include "Logger/Logger.h"

int main() {
    Logger* logger = newLogger();
    logger->addRecord(logger, "Logger inited");
    logger->addRecord(logger, "Running runConsoleEngine()");
    runConsoleEngine(logger);
    logger->addRecord(logger, "Returned from runConsoleEngine()");
    logger->printRecords(logger);
    return 0;
}
