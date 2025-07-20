#include "queue.h"

// Initial declaration of the static member function
// pointers in the linked_list class.
//
void *(*queue::malloc_fptr)(size_t) = nullptr;
void (*queue::free_fptr)(void *) = nullptr;
