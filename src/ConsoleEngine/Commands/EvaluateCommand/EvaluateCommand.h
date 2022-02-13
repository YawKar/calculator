#ifndef _EVALUATE_COMMAND_HEADER
#define _EVALUATE_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"
#include <stdio.h>

int performEvaluateCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream);

#endif