#include "EvaluateCommand.h"
#include <stdio.h>
#include <complex.h>
#include "../../../Kernel/AllNodes.h"
#include "../../../Kernel/EvaluateFunctions/EvaluateFunctions.h"

int performEvaluateCommand(LineArgs* lineArgs, VariablesTable* vTable, Logger* logger) {
    if (lineArgs->argsNumber != 2) {
        printf("Command 'evaluate' must have 1 argument but %d were provided.\n", lineArgs->argsNumber - 1);
        printf("Cancelling...\n");
        logger->addRecord(logger, "'evaluate': incorrect amount of arguments");
        return 0;
    }
    if (vTable->containVariable(vTable, lineArgs->args[1])) {
        VariableNode* variableNode = (VariableNode*)vTable->getVariableNode(vTable, lineArgs->args[1]);
        if (variableNode->operands->size == 0) {
            printf("Variable '%s' not assigned. Please provide a definition for the variable.\n", lineArgs->args[1]);
            printf("Cancelling...\n");
            logger->addRecord(logger, "'evaluate': variable wasn't assigned");
            return 0;
        } else {
            double complex result = evaluateVariableNode(variableNode);
            printf("Result: (%lf ; %lfi)\n", creal(result), cimag(result));
            return 0;
        }
    } else {
        printf("Unknown variable name '%s'\n", lineArgs->args[1]);
        printf("Cancelling...\n");
        logger->addRecord(logger, "'evaluate': unknown variable name");
        return 0;
    }
    return 0;
}