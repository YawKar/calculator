#include "HelpCommand.h"
#include <stdio.h>
#include <stdlib.h>

char* readContentOfFile(FILE* file) {
    if (file == NULL)
        return "";
    char* content = NULL;
    int contentLen = 0;
    int curIndex = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (curIndex == contentLen) {
            char* newContent = (char*)calloc(contentLen * 2 + 1, sizeof(char));
            for (int i = 0; i < curIndex; ++i)
                newContent[i] = content[i];
            if (content)
                free(content);
            content = newContent;
            contentLen = contentLen * 2 + 1;
        }
        content[curIndex++] = c;
    }
    if (curIndex == contentLen) {
        char* newContent = (char*)malloc(sizeof(char) * (contentLen + 1));
        for (int i = 0; i < contentLen; ++i)
            newContent[i] = content[i];
        if (content)
            free(content);
        content = newContent;
        contentLen += 1;
    }
    content[curIndex++] = '\0';
    fclose(file);
    return content;
}

int performHelpCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger) {
    if (lineArgs->argsNumber != 1) {
        printf("Command 'help' doesn't have any arguments, but %d were provided\n", lineArgs->argsNumber - 1);
        logger->addRecord(logger, "'help': incorrect amount of arguments.");
        return 0;
    }
    FILE* helpMenuFile = fopen("helpMenuText.txt", "r");
    char* helpMenu = readContentOfFile(helpMenuFile);
    printf("%s\n", helpMenu);
    if (helpMenu)
        free(helpMenu);
    logger->addRecord(logger, "Printed help-menu");
    return 0;
}