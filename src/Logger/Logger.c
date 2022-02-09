#include <stdlib.h>
#include <stdio.h>
#include "Logger.h"

void lengthenLogger(Logger* logger) {
    char** newRecs = (char**)malloc(sizeof(char*) * (logger->recordsCapacity * 2 + 1));
    for (int i = 0; i < logger->recordsNumber; ++i) {
        newRecs[i] = logger->records[i];
    }
    if (logger->records)
        free(logger->records);
    logger->records = newRecs;
    logger->recordsCapacity = logger->recordsCapacity * 2 + 1;
}

void addRecord(Logger* logger, char* record) {
    if (logger->recordsCapacity == logger->recordsNumber) {
        lengthenLogger(logger);
    }
    logger->records[logger->recordsNumber] = record;
    ++logger->recordsNumber;
}

char* getRecord(Logger* logger, int index) {
    return logger->records[index];
}

void printRecords(Logger* logger) {
    printf("Logger '%s' starts printing:\n", logger->name);
    for (int recordIndex = 0; recordIndex < logger->recordsNumber; ++recordIndex) {
        printf("%s:%5dr: %s\n", logger->name, recordIndex, logger->records[recordIndex]);
    }
    printf("Logger '%s' ended its printing\n", logger->name);
}

Logger* newLogger() {
    Logger* logger = (Logger*)malloc(sizeof(Logger));
    logger->recordsNumber = 0;
    logger->recordsCapacity = 0;
    logger->records = NULL;
    logger->name = "default";
    logger->addRecord = &addRecord;
    logger->printRecords = &printRecords;
    logger->getRecord = &getRecord;
    return logger;
}
