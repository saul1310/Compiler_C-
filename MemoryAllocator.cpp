
#include "utils.h"
#include <cstdlib> 
#include <new>      
#include <iostream>


std::size_t alignSize(std::size_t size, std::size_t alignment) {
    return (size + alignment - 1) & ~(alignment - 1);
}
