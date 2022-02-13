#include "FileFunctions.h"
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
    return content;
}