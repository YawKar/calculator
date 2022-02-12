#ifndef _SET_COMMAND_HEADER
#define _SET_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"


int performSetCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger);

#endif