#ifndef _COMMAND_LINE_INTERFACE
#define _COMMAND_LINE_INTERFACE
#include "../Logger/Logger.h"
#include "LineArgs/LineArgs.h"
#include "../Kernel/VariablesTable/VariablesTable.h"
#include <stdio.h>

char* getInputLine();
int performCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream);

#endif
