#include "memoryallocator.h"
#include <cstring> // For memset
#include <climits> // For UINT_MAX

MemoryAllocator::MemoryAllocator(size_t size) : totalSize(size) {
    memoryPool = new char[size];
    head = reinterpret_cast<Block*>(memoryPool);
    head->size = size - sizeof(Block);
    head->free = true;
    head->next = nullptr;
}

MemoryAllocator::~MemoryAllocator() {
    delete[] memoryPool;
}

void* MemoryAllocator::allocate(size_t size) {
    Block* bestFit = findBestFitBlock(size);
    if (!bestFit) {
        return nullptr; // No suitable block found
    }
    if (bestFit->size > size + sizeof(Block)) {
        splitBlock(bestFit, size);
    }
    bestFit->free = false;
    return reinterpret_cast<void*>(reinterpret_cast<char*>(bestFit) + sizeof(Block));
}

void MemoryAllocator::deallocate(void* ptr) {
    if (!ptr) return;  // if does not exist
    
    Block* block = reinterpret_cast<Block*>(reinterpret_cast<char*>(ptr) - sizeof(Block));
    block->free = true;
    mergeFreeBlocks();
}

MemoryAllocator::Block* MemoryAllocator::findBestFitBlock(size_t size) {
    Block* bestFit = nullptr;
    Block* current = head;
    size_t minSize = UINT_MAX;

    while (current) {
        if (current->free && current->size >= size) {
            if (current->size < minSize) {
                minSize = current->size;
                bestFit = current;
            }
        }
        current = current->next;
    }

    return bestFit;
}

void MemoryAllocator::splitBlock(Block* block, size_t size) {
    Block* newBlock = reinterpret_cast<Block*>(reinterpret_cast<char*>(block) + sizeof(Block) + size);
    newBlock->size = block->size - size - sizeof(Block);
    newBlock->free = true;
    newBlock->next = block->next;

    block->size = size;
    block->next = newBlock;
}

void MemoryAllocator::mergeFreeBlocks() {
    Block* current = head;
    while (current && current->next) {
        if (current->free && current->next->free) {
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}
