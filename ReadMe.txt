This software is a Memory Allocator written in c++.
The basic functions that should work are allocating memory, and freeing memory 

First we must find our total dyanamic memory and its size.

Next we constructg a bitmap with A ratio of one bit per block


---First Fit Allocation ---
When we can a malloc, asking for a certain amount of memory, we want to allocate a number of blocks that is equal to the requested amount.
On way to do this would be to scan the bnitmap from left to right looking for the desired space. If it fails it will tell the user that its out of memory.




---Best Fit Allocation ---

Scan entire bitmap, which will take more time, but return the smallest spot large enough to fit all the requested data, resulting in perfect fits if possible 

Fragmentation--> Cheese type bitmap where there is enough space, but not in a continous subsequence, and cannot be held.
Defragmenatation is possible but takes a lot of time and is best to be avoided Additional Function could be Reallocate 

Granularity vs space occupation?
