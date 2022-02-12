#include "StringFunctions.h"
#include <string.h>
#include <stdlib.h>

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

char* copyString(char* originalString) {
    int origStrSize = strlen(originalString);
    char* copied = (char*)malloc(sizeof(char) * (origStrSize + 1));
    for (int i = 0; i < origStrSize; ++i) {
        copied[i] = originalString[i];
    }
    copied[origStrSize] = '\0';
    return copied;
}

char* concatStrings(char* string1, char* string2) {
    int string1len = strlen(string1);
    int string2len = strlen(string2);
    char* finalString = (char*)malloc(sizeof(char) * (string1len + string2len + 1));
    for (int i = 0; i < string1len; ++i)
        finalString[i] = string1[i];
    for (int i = 0; i < string2len; ++i)
        finalString[i + string1len] = string2[i];
    finalString[string1len + string2len] = '\0';
    return finalString;
}