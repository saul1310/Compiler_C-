#ifndef ALLOCATOR_UTILS_H
#define ALLOCATOR_UTILS_H

namespace AllocatorUtils {

    // Aligns a given pointer to the nearest multiple of 'alignment'
    inline std::uintptr_t AlignPointer(std::uintptr_t ptr, std::size_t alignment) {
        std::size_t misalignment = ptr % alignment;
        if (misalignment == 0) {
            return ptr;
        }
        return ptr + (alignment - misalignment);
    }

  // Checks if the pointer is aligned to the required alignment
    inline bool IsAligned(std::uintptr_t ptr, std::size_t alignment) {
        return (ptr % alignment) == 0;
    }
 inline std::size_t CalculatePadding(std::uintptr_t ptr, std::size_t alignment) {
        std::size_t misalignment = ptr % alignment;
        if (misalignment == 0) {
            return 0;
        }
        return alignment - misalignment;
    }
