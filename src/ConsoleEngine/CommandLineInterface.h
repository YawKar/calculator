#ifndef _COMMAND_LINE_INTERFACE
#define _COMMAND_LINE_INTERFACE
#include "../Logger/Logger.h"

typedef struct LineArgs LineArgs;
struct LineArgs {
    char** args;
    int argsNumber;
};
LineArgs* newLineArgs();

LineArgs* parseLineArgs(char* line);
char* getInputLine();
int performCommand(LineArgs* lineArgs, Logger* logger);
int areStringsEqual(char* string1, char* string2);

#endif
