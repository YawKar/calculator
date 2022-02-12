#ifndef _SHOWVARS_COMMAND_HEADER
#define _SHOWVARS_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"


int performShowvarsCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger);

#endif