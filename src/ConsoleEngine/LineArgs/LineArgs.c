#include "LineArgs.h"
#include <stdlib.h>
#include <string.h>

LineArgs* newLineArgs() {
    LineArgs* lineArgs = (LineArgs*)malloc(sizeof(LineArgs));
    lineArgs->argsNumber = 0;
    lineArgs->args = NULL;
    return lineArgs;
}

void addArgToLineArgs(LineArgs* lineArgs, char* arg) {
    char** newArgs = (char**)malloc(sizeof(char*) * (lineArgs->argsNumber + 1));
    for (int i = 0; i < lineArgs->argsNumber; ++i)
        newArgs[i] = lineArgs->args[i];
    newArgs[lineArgs->argsNumber] = arg;
    if (lineArgs->args)
        free(lineArgs->args);
    lineArgs->args = newArgs;
    ++lineArgs->argsNumber;
}


LineArgs* parseLineArgs(char* line) {
    LineArgs* lineArgs = newLineArgs();
    int lineLen = strlen(line);
    int argLen = 0;
    for (int i = 0; i < lineLen; ++i) {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            if (argLen) {
                char* arg = (char*)calloc(argLen + 1, sizeof(char));
                for (int pos = i - argLen; pos < i; ++pos)
                    arg[pos - (i - argLen)] = line[pos];
                arg[argLen] = '\0';
                addArgToLineArgs(lineArgs, arg);
                argLen = 0;
            }
        } else {
            ++argLen;
        }
    }
    if (argLen) {
        char* arg = (char*)calloc(argLen + 1, sizeof(char));
        for (int pos = lineLen - argLen; pos < lineLen; ++pos)
            arg[pos - (lineLen - argLen)] = line[pos];
        arg[argLen] = '\0';
        addArgToLineArgs(lineArgs, arg);
        argLen = 0;
    }
    return lineArgs;
}