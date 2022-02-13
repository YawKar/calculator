#include "SetCommand.h"
#include "../../../Kernel/Parser/Parser.h"
#include "../../../StringFunctions/StringFunctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int performSetCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger, FILE* outputStream) {
    if (lineArgs->argsNumber < 3) {
        fprintf(outputStream, "Command 'set' must have at least 3 arguments, but %d were provided\n", lineArgs->argsNumber - 1);
        logger->addRecord(logger, "'set': incorrect amount of arguments.");
        return 0;
    }
    char* variableName = copyString(lineArgs->args[1]);
    // TO DO: check if the given variable name is correct
    char* variableDefinition = copyString(lineArgs->args[2]);
    for (int i = 3; i < lineArgs->argsNumber; ++i) {
        char* concatted = concatStrings(variableDefinition, lineArgs->args[i]);
        if (variableDefinition)
            free(variableDefinition);
        variableDefinition = concatted;
    }
    // Now parsing the expression
    VariableNode* variableNode;
    if (vTable->containVariable(vTable, variableName)) {
        variableNode = (VariableNode*)vTable->getVariableNode(vTable, variableName);
        variableNode->operands->size = 0;
    } else {
        variableNode = newVariableNode();
        vTable->assignVariableNode(vTable, variableName, variableNode);
    }
    GraphNode* parsedDefinition = newGraphNode();
    parseExpression(parsedDefinition, variableDefinition, 0, strlen(variableDefinition), vTable);
    containerPush(variableNode->operands, (void*)parsedDefinition);
    return 0;
}