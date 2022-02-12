#ifndef _INFO_COMMAND_HEADER
#define _INFO_COMMAND_HEADER
#include "../../LineArgs/LineArgs.h"
#include "../../../Kernel/VariablesTable/VariablesTable.h"
#include "../../../Logger/Logger.h"

int performInfoCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger);

#endif