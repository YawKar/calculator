#ifndef _VARIABLES_TABLE_HEADER
#define _VARIABLES_TABLE_HEADER
#include "../../PointerContainer/PointerContainer.h"
#include "../Nodes/VariableNode/VariableNode.h"

typedef struct VariablesTable VariablesTable;
struct VariablesTable {
    PointerContainer* variableNames;
    PointerContainer* variableNodes;
    int (*size) ();
    int (*containVariable) (VariablesTable* variablesTable, char* variableName);
    void* (*getVariableNode) (VariablesTable* variablesTable, char* variableName);
    void (*assignVariableNode) (VariablesTable* variablesTable, char* variableName, VariableNode* variableNode);
    void (*addVariableName) (VariablesTable* variablesTable, char* variableName);
};

VariablesTable* newVariablesTable();

#endif