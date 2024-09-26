
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

int main() {
    const std::size_t memoryPoolSize = 1024;  // Total size of memory pool
    const std::size_t alignment = 16;  // Alignment boundary

  try {
        MemoryAllocator allocator(memoryPoolSize, alignment);

        // Allocate some memory
        void* block1 = allocator.allocate(64);
        void* block2 = allocator.allocate(128);
   std::cout << "Block1 Address: " << block1 << " Is Aligned: " << isAligned(block1, alignment) << std::endl;
        std::cout << "Block2 Address: " << block2 << " Is Aligned: " << isAligned(block2, alignment) << std::endl;

        // Initialize memory for debugging
        initializeMemory(block1, 64, 0xAA);
        initializeMemory(block2, 128, 0xBB);

        // Print memory content
        std::cout << "Block1 Memory Content: ";
        printMemoryBlock(block1, 64);
        std::cout << "Block2 Memory Content: ";
        printMemoryBlock(block2, 128);

        // Reset the allocator
        allocator.reset();

        // Allocate again after reset
        void* block3 = allocator.allocate(256);
        std::cout << "Block3 Address: " << block3 << " Is Aligned: " << isAligned(block3, alignment) << std::endl;

    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation failed!" << std::endl;
    }

    return 0;
}
