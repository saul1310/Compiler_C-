
#define ALLOCATORUTILS_H

#include <cstddef>
#include <iostream>


std::size_t alignSize(std::size_t size, std::size_t alignment);


void printMemoryBlock(const void* ptr, std::size_t size);

// Function to check if a pointer is aligned to a specific boundary
bool isAligned(const void* ptr, std::size_t alignment);

// Function to initialize a memory block with a specific value (for debugging)
void initializeMemory(void* ptr, std::size_t size, std::uint8_t value);

#endif // ALLOCATORUTILS_H
