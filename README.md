# ParallelPrograming-Assignments

What valgrind displayed before fixing the code:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./assignment1
==9009== Memcheck, a memory error detector
==9009== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9009== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==9009== Command: ./assignment1
==9009== 
==9009== Invalid write of size 4
==9009==    at 0x1091C6: main (main.c:7)
==9009==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==9009==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9009==    by 0x109185: main (main.c:5)
==9009== 
==9009== Conditional jump or move depends on uninitialised value(s)
==9009==    at 0x1091F4: main (main.c:9)
==9009==  Uninitialised value was created by a stack allocation
==9009==    at 0x109169: main (main.c:3)
==9009== 
==9009== Invalid read of size 4
==9009==    at 0x1091EF: main (main.c:9)
==9009==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==9009==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9009==    by 0x109185: main (main.c:5)
==9009== 
==9009== 
==9009== HEAP SUMMARY:
==9009==     in use at exit: 40 bytes in 1 blocks
==9009==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==9009== 
==9009== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9009==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==9009==    by 0x109185: main (main.c:5)
==9009== 
==9009== LEAK SUMMARY:
==9009==    definitely lost: 40 bytes in 1 blocks
==9009==    indirectly lost: 0 bytes in 0 blocks
==9009==      possibly lost: 0 bytes in 0 blocks
==9009==    still reachable: 0 bytes in 0 blocks
==9009==         suppressed: 0 bytes in 0 blocks
==9009== 
==9009== For lists of detected and suppressed errors, rerun with: -s
==9009== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)

What have I fixed:

In the lines 5 and 6 of my fixed code, I initialized variables ipos and ival, and I gave them
a value of 0. This would prevent the Uninitialized Memory issue.    

In the line 10 of my fixed code, I added a if condition that checks if the array has the absence of a valid memory address (NULL). If array is NULL than a user gets a message "Memory allocation failed" and returns 1 to show the user thats the error. 

In the lines 17 and 18, I have deleted equals (=) sign from the second argument i<=10, (after rewriting: i<10), because that prevents overwriting the memory, which means that I have prevented writing to a memory location which is not owned by a variable, in our case out of bounds of our array. Why out of bounds, because in our task the valid array length is 10 (from 0 to 9), and we are trying to access its 11th element. 

And the last thing I have fixed is in the line 22, i have freed the memory that was previously allocated because it prevents memory leaks and because the memory is not needed anymore. 

What valgrind displayed after fixing the code: 

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./assignment1
==11506== Memcheck, a memory error detector
==11506== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11506== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==11506== Command: ./assignment1
==11506== 
==11506== 
==11506== HEAP SUMMARY:
==11506==     in use at exit: 0 bytes in 0 blocks
==11506==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==11506== 
==11506== All heap blocks were freed -- no leaks are possible
==11506== 
==11506== For lists of detected and suppressed errors, rerun with: -s
==11506== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)