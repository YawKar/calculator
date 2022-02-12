#ifndef _EXIT_COMMAND_HEADER
#define _EXIT_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"


int performExitCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger);

#endif