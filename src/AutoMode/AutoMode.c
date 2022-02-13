#include "AutoMode.h"
#include "../StringFunctions/StringFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../FileFunctions/FileFunctions.h"
#include "../Kernel/VariablesTable/VariablesTable.h"
#include "../ConsoleEngine/LineArgs/LineArgs.h"
#include "../ConsoleEngine/CommandLineInterface.h"

void runAutoMode(int argc, char* argv[], Logger* logger) {
    char* inputFileName = "input.txt";
    char* outputFileName = "output.txt";
    for (int i = 1; i < argc; ++i) {
        if (areStringsEqual(argv[i], "-f")) {
            if (i + 1 >= argc) {
                logger->addRecord(logger, "AutoMode: -f was provided without an actual filename");
                printf("AutoMode: -f was provided without an actual filename\n");
                return;
            } else {
                inputFileName = copyString(argv[i + 1]);
                ++i;
            }
        } else if (areStringsEqual(argv[i], "-o")) {
            if (i + 1 >= argc) {
                logger->addRecord(logger, "AutoMode: -o was provided without an actual filename");
                printf("AutoMode: -o was provided without an actual filename\n");
                return;
            } else {
                outputFileName = copyString(argv[i + 1]);
                ++i;
            }
        }
    }
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("AutoMode: input file '%s' doesn't exist\n", inputFileName);
        return;
    }
    FILE* outputFile = fopen(outputFileName, "w");
    char* inputContent = readContentOfFile(inputFile);
    fclose(inputFile);
    int inputContentLength = strlen(inputContent);
    int curLineStart = 0;
    VariablesTable* vTable = newVariablesTable();
    for (int i = 0; i < inputContentLength; ++i) {
        if (inputContent[i] == '\n') {
            // Process current line
            char* currentLine = (char*)malloc(sizeof(char) * (i - curLineStart + 1));
            for (int j = 0; j < i - curLineStart; ++j)
                currentLine[j] = inputContent[curLineStart + j];
            currentLine[i - curLineStart] = '\0';
            LineArgs* lineArgs = parseLineArgs(currentLine);
            int exit = performCommand(lineArgs, vTable, logger, outputFile);
            if (exit) {
                fclose(outputFile);
                return;
            }
            curLineStart = i + 1;
        }
    }
    fclose(outputFile);
}