#include "MemoryAllocator.h"
#include <cstring>
#include<climits>

MemoryAllocator::MemoryAllocator(size_t size) : totalSize(size){
    memoryPool = new char [size];
    head=reinterpret_cast<Block*> (memoryPool);
    head --> size = size -  sizeof(Block);
    head--> free = true;
    head --> next = nullptr;



}


