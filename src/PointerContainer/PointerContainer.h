#ifndef _POINTER_CONTAINER_HEADER
#define _POINTER_CONTAINER_HEADER

struct PointerContainer {
    void** content;
    int capacity;
    int size;
};
typedef struct PointerContainer PointerContainer;

PointerContainer* newPointerContainer();
void* containerGetIndex(PointerContainer* container, int index);
void containerPush(PointerContainer* container, void* element);

#endif