#ifndef _LOGGER_HEADER
#define _LOGGER_HEADER
typedef struct Logger Logger;
struct Logger {
    int recordsNumber;
    char** records;
    int recordsCapacity;
    char* name;
    void (*addRecord)(Logger* logger, char* record);
    char* (*getRecord)(Logger* logger, int index);
    void (*printRecords)(Logger* logger);
};

Logger* newLogger();

#endif
