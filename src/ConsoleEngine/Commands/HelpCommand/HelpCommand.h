#ifndef _HELP_COMMAND_HEADER
#define _HELP_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"


int performHelpCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger);

#endif