// The constructor first sets up the memory pool and initializes the free list to point to the entire pool 
// The allocate function then searches for a free block, splits it if neccesary, and returns the portion to the user 
// the deallocate function then will mark the block as free and try to merge it to avoid fragmentation 
// The destructor ensures when the allocator is no longer needed the entire pool is freed


#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H

#include <cstddef>  // for size_t

struct BlockHeader {
    size_t size;    // Size of the memory block
    bool isFree;    // Whether the block is free or allocated
    BlockHeader* next;  // Pointer to the next block in the free list
};

class MemoryAllocator {
private:
    void* memoryPool;    // Pointer to the start of the memory pool
    size_t poolSize;     // Size of the entire memory pool
    BlockHeader* freeList; // Linked list of free memory blocks

public:
    // Constructor that initializes the memory pool
    MemoryAllocator(size_t size);

    // Destructor that frees the memory pool
    ~MemoryAllocator();

    // Allocate a block of memory of the given size
    void* allocate(size_t size);

    // Deallocate a block of memory, returning it to the free list
    void deallocate(void* ptr);
};

#endif // MEMORYALLOCATOR_H
