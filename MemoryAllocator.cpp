
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

