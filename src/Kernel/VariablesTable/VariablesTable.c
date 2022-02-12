#include "VariablesTable.h"
#include "../../StringFunctions/StringFunctions.h"
#include <stdlib.h>
#include <string.h>

int size(VariablesTable* vTable) {
    return vTable->variableNames->size;
}

int getIndexByName(VariablesTable* vTable, char* variableName) {
    for (int i = 0; i < vTable->size(vTable); ++i) {
        if (areStringsEqual((char*)vTable->variableNames->content[i], variableName))
            return i;
    }
    return -1;
}

int containVariable(VariablesTable* vTable, char* variableName) {
    return getIndexByName(vTable, variableName) != -1;
}

void* getVariableNode(VariablesTable* vTable, char* variableName) {
    int index = getIndexByName(vTable, variableName);
    return index == -1 ? NULL : vTable->variableNodes->content[index];
}

void addVariableName(VariablesTable* vTable, char* variableName) {
    if (containVariable(vTable, variableName))
        return;
    containerPush(vTable->variableNames, (void*)copyString(variableName));
    containerPush(vTable->variableNodes, NULL);
}

void assignVariableNode(VariablesTable* vTable, char* variableName, VariableNode* variableNode) {
    int index = getIndexByName(vTable, variableName);
    if (index == -1) {
        addVariableName(vTable, variableName);
        index = getIndexByName(vTable, variableName);
    }
    vTable->variableNodes->content[index] = (void*)variableNode;
}

VariablesTable* newVariablesTable() {
    VariablesTable* vTable = (VariablesTable*)malloc(sizeof(VariablesTable));
    vTable->variableNodes = newPointerContainer();
    vTable->variableNames = newPointerContainer();
    vTable->containVariable = &containVariable;
    vTable->getVariableNode = &getVariableNode;
    vTable->size = &size;
    vTable->addVariableName = &addVariableName;
    vTable->assignVariableNode = &assignVariableNode;
    return vTable;
}