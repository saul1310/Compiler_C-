This software is a Memory Allocator written in c++.
The basic functions that should work are allocating memory, and freeing memory 
The data structure used to represent available data should be implemented as a bitmap.


---First Fit Allocation ---
When the allocator is called the input should be the requested amount of memory. we want to allocate a number of blocks that is equal to the requested amount.
On way to do this would be to scan the bitmap from left to right until a location with enough space is found. If it fails it will tell the user that its out of memory.




---Best Fit Allocation ---

Algorithim will Scan the entire bitmap, which will take more time, but return the smallest spot large enough to fit all the requested data, resulting in perfect fits if possible 

Fragmentation--> Cheese type bitmap where there is enough space, but not in a continuous subsequence, and cannot be held.
Defragmentation is possible but takes a lot of time and is best avoided. An additional Function could be Reallocating memory to create a best fit that is even more efficient.
Granularity vs space occupation?


Please contribute anything you think would be helpful to this repository!


This is essentially completed, i am looking for a place to advertise this as an alternative to the standard allocator right now.
