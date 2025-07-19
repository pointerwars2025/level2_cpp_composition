#ifndef QUEUE_H_
#define QUEUE_H_

#include "linked_list.h"

class queue{
  public:
    // Default constructor.
    //
    queue();

    // Destructor.
    //
    virtual ~queue();

    // New and delete operators. Needed to support
    // having a custom allocator, which the testing
    // framework uses, but you may also want to use
    // to improve the performance in Levels 2, 3, and
    // 4.
    //
    void * operator new(size_t size);
    void operator delete(void * ptr);

    // Methods to implement.
    // Note that we have a C like interface here, 
    // return value tells us if it worked, and the
    // popped or next value is returned via pointer.
    // Returns TURE on success, FALSE otherwise.
    //
    bool push(unsigned int data);
    // Do not modify popped_data if pop() fails.
    //
    bool pop(unsigned int * popped_data);
    bool has_next() const;
    // Do not modify next_data if next() fails.
    //
    bool next(unsigned int * next_data) const;
    
    // Returns the size of the queue.
    //
    size_t size() const;

    // Static members for memory allocation. Very C like.
    //
    static void register_malloc(void * (*malloc)(size_t));
    static void register_free(void (*free)(void*));
    static void * (*malloc_fptr)(size_t);
    static void (*free_fptr)(void*);

    // No operator overload for [] operator. It's a queue,
    // push and pop is what you use.
    //

  private:
    // This queue.h uses composition to contain
    // the linked list that the queue uses. There
    // is another Github repository that uses
    // inheritance, if you prefer that design decision
    // to this one.
    //
    linked_list * ll;
};

#endif
