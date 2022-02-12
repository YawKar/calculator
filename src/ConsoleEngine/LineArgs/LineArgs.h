#ifndef _LINE_ARGS_HEADER
#define _LINE_ARGS_HEADER

struct LineArgs {
    char** args;
    int argsNumber;
};
typedef struct LineArgs LineArgs;

LineArgs* newLineArgs();
LineArgs* parseLineArgs(char* line);
void addArgToLineArgs(LineArgs* lineArgs, char* arg);

#endif