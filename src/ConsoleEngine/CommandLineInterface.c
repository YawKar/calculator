#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CommandLineInterface.h"
#include "../Logger/Logger.h"

LineArgs* newLineArgs() {
    LineArgs* lineArgs = (LineArgs*)malloc(sizeof(LineArgs));
    lineArgs->args = NULL;
    lineArgs->argsNumber = 0;
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

int areStringsEqual(char* string1, char* string2) {
    int str1len = strlen(string1);
    int str2len = strlen(string2);
    if (str1len != str2len)
        return 0;
    for (int i = 0; i < str1len; ++i)
        if (string1[i] != string2[i])
            return 0;
    return 1;
}

// Returns 1 if 'exit' command was entered.
int performCommand(LineArgs* lineArgs, Logger* logger) {
    static char* helpMenuHint = "Type 'help' to see commands.";
    static char* helpMenu = "help:\nhelp - prints these helpnotes\nexit - exits from engine\nset [variable-name] [declaration] - sets a new variable 'variable-name' with the value of evaluated 'declaration'";
    if (lineArgs->argsNumber == 0) {
        printf("No commands were found. %s\n", helpMenuHint);
        logger->addRecord(logger, "Empty lineArgs");
        return 0;
    }
    if (areStringsEqual(lineArgs->args[0], "help")) {
        if (lineArgs->argsNumber != 1) {
            printf("Command 'help' doesn't have any arguments but %d were provided\n", lineArgs->argsNumber - 1);
            logger->addRecord(logger, "'help': incorrect amount of arguments");
            return 0;
        }
        printf("%s\n", helpMenu);
        logger->addRecord(logger, "Printed help-menu");
        return 0;
    } else if (areStringsEqual(lineArgs->args[0], "exit")) {
        if (lineArgs->argsNumber != 1) {
            printf("Command 'exit' doesn't have any arguments but %d were provided\n", lineArgs->argsNumber - 1);
            logger->addRecord(logger, "'exit': incorrect amount of arguments");
            return 0;
        }
        logger->addRecord(logger, "Exit command performed");
        return 1;
    } else if (areStringsEqual(lineArgs->args[0], "set")) {
        if (lineArgs->argsNumber < 3) {
            printf("Command 'set' must have at least 2 arguments but %d were provided\n", lineArgs->argsNumber - 1);
            logger->addRecord(logger, "'set': incorrect amount of arguments");
            return 0;
        }
        logger->addRecord(logger, "set variable <...> <...> ?_?");
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
