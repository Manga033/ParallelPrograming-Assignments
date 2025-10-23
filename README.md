# ParallelPrograming-Assignments
Spreadsheet: https://docs.google.com/spreadsheets/d/14WPEJThu9rSow7j3yUn7-SRDtYxXVM8qkcBibSHWrgk/edit?gid=0#gid=0

What does this code do?

This program measures how long it takes to initialize data in Array of Structures of Arrays (AoSoA) data layout. 

Missing code I have implemented: 

Line 23: Allocated the data. This line of code dynamically alocates an array of structures. Each element in this array (AoSoA[j]) has three array length of V. This represents the AoSoA memory layout. To explain the logic if num_blocks = 3 and V = 4, then total data capacity is 3 * 4 = 12 RGB triplets. 

Line 45: Freed up the memory. This line of code deallocates the memory that was previously in line 23 allocated with the command new. It is important to do this so we can prevent memory leaks. 

Spreadsheet explaination: 

V represents the vector length, it controls how many elements are processed in one block. 
1K, 10K, 100K, 1M, 10M represents different array lengths. 
Thanks to these tests, we measured the execution times for all array lengths and vector lengths and wrote results in the cells. 
Graph shows us execution times. We can clearly see that if the vector length increases, the execution time also increases for the given array length. It is obvious why, more data needs to be processed. 