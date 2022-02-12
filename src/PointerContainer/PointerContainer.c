#include "PointerContainer.h"
#include <stdlib.h>

PointerContainer* newPointerContainer() {
    PointerContainer* container = (PointerContainer*)malloc(sizeof(PointerContainer));
    container->capacity = 0;
    container->size = 0;
    container->content = 0;
    return container;
}

void lengthenPointerContainer(PointerContainer* container) {
    int newCapacity = container->capacity * 2 + 1;
    void** newContent = (void**)malloc(sizeof(void*) * newCapacity);
    for (int i = 0; i < container->size; ++i) {
        newContent[i] = container->content[i];
    }
    if (container->content)
        free(container->content);
    container->content = newContent;
    container->capacity = newCapacity;
}

void* containerGetIndex(PointerContainer* container, int index) {
    if (index < 0 || container->size <= index)
        return NULL;
    return container->content[index];
}

void containerPush(PointerContainer* container, void* element) {
    if (container->size == container->capacity) {
        lengthenPointerContainer(container);
    }
    container->content[container->size++] = element;
}