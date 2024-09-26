
#include "utils.h"
#include <cstdlib> 
#include <new>      
#include <iostream>


std::size_t alignSize(std::size_t size, std::size_t alignment) {
    return (size + alignment - 1) & ~(alignment - 1);
}

void printMemoryBlock(const void* ptr, std::size_t size) {
    const unsigned char* bytePtr = static_cast<const unsigned char*>(ptr);
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << std::hex << static_cast<int>(bytePtr[i]) << " ";
    }
    std::cout << std::dec << std::endl;  // Reset output to decimal
}

bool isAligned(const void* ptr, std::size_t alignment) {
    return reinterpret_cast<std::uintptr_t>(ptr) % alignment == 0;
}

bool isAligned(const void* ptr, std::size_t alignment) {
    return reinterpret_cast<std::uintptr_t>(ptr) % alignment == 0;
}

class MemoryAllocator {
public:
    MemoryAllocator(std::size_t totalSize, std::size_t alignment)
        : totalSize(totalSize), alignment(alignment) {
        // Allocate aligned memory
        basePtr = std::malloc(totalSize);
        if (!basePtr) {
            throw std::bad_alloc();
        }
        currentPtr = basePtr;
    }

 ~MemoryAllocator() {
        // Free the memory
        std::free(basePtr);
    }

   void* allocate(std::size_t size) {
        size = alignSize(size, alignment);  // Align the requested size
        if (static_cast<std::uint8_t*>(currentPtr) + size > static_cast<std::uint8_t*>(basePtr) + totalSize) {
            throw std::bad_alloc();  // Not enough memory
        }

  void* allocatedPtr = currentPtr;
        currentPtr = static_cast<std::uint8_t*>(currentPtr) + size;  // Move the pointer forward
        return allocatedPtr;
    }

void deallocate(void* ptr) {
       needs to be implemented 
    }

 void reset() {
        currentPtr = basePtr;  // Reset the allocator to reuse memory
    }

private:
    std::size_t totalSize;
    std::size_t alignment;
    void* basePtr;
    void* currentPtr;
};
