Output after running timestep.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ ls
main.c    README.md  timer.h     timestep.h       timestep_opt2.c
Makefile  timer.c    timestep.c  timestep_opt1.c  timestep_opt3.c
student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make 
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o main.o main.c
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timestep.o timestep.c
timestep.c:9:22: missed: couldn't vectorize loop
timestep.c:9:22: missed: not vectorized: control flow in loop.
timestep.c:11:25: missed: statement clobbers memory: wavespeed_46 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timer.o timer.c
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep.o timer.o -lm
student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ ./stream_triad 
Minimum dt is 0.016964

Output after running timestep_opt1.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timestep_opt1.o timestep_opt1.c
timestep_opt1.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:11:7: missed: couldn't vectorize loop
timestep_opt1.c:11:7: missed: not vectorized: control flow in loop.
timestep_opt1.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:12:22: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep_opt1.o timer.o -lm
student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ ./stream_triad 
Minimum dt is 0.016964

Output after running timestep_opt2.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timestep_opt2.o timestep_opt2.c
timestep_opt2.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:11:7: missed: couldn't vectorize loop
timestep_opt2.c:11:7: missed: not vectorized: control flow in loop.
timestep_opt2.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:12:22: missed: statement clobbers memory: wavespeed_58 = sqrt (_9);
gcc -g -O3 -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep_opt2.o timer.o -lm
student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ ./stream_triad 
Minimum dt is 0.016964

Output afer running timestep_opt3.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ make
gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o main.o main.c
main.c:10:22: optimized: loop vectorized using 32 byte vectors
main.c:20:15: missed: statement clobbers memory: mymindt_6 = timestep (10000000, 9.800000000000000710542735760100185871124267578125e+0, 9.499999999999999555910790149937383830547332763671875e-1, &celltype, &H, &U, &V, &dx, &dy);
/usr/include/x86_64-linux-gnu/bits/stdio2.h:112:10: missed: statement clobbers memory: __printf_chk (1, "Minimum dt is %lf\n", mymindt_6);
gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timestep_opt3.o timestep_opt3.c
timestep_opt3.c:8:9: optimized: loop vectorized using 32 byte vectors
timestep_opt3.c:10:7: optimized: loop vectorized using 16 byte vectors
timestep_opt3.c:8:9: optimized: loop vectorized using 32 byte vectors
gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed   -c -o timer.o timer.c
timer.c:9:5: missed: statement clobbers memory: clock_gettime (1, tstart_cpu_2(D));
timer.c:14:5: missed: statement clobbers memory: clock_gettime (1, &tstop_cpu);
gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -o stream_triad main.o timestep_opt3.o timer.o -lm
student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ ./stream_triad 
Minimum dt is 0.016964

Output after running this command likwid-perfctr -C 0 -f -g MEM_DP ./stream_triad: 

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ likwid-perfctr -C 0 -f -g MEM_DP ./stream_triad
--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
CPU type:       Intel Core SandyBridge processor
CPU clock:      3.29 GHz
ERROR - [/home/student/likwid/src/perfgroup.c:perfgroup_readGroup:830] No such file or directory.
Cannot read group file MEM_DP.txt. Searched in /usr/local/share/likwid/perfgroups/sandybridge/MEM_DP.txt and /home/student/.likwid/groups/sandybridge/MEM_DP.txt
ERROR - [/home/student/likwid/src/perfmon.c:perfmon_addEventSet:2533] Permission denied.
Access to performance group MEM_DP not allowed

As the access is not allowed, we will use linux friendly command perf. 

Output after checking performance for timestep.c: 

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ sudo perf stat -e branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions ./stream_triad
Minimum dt is 0.016964

 Performance counter stats for './stream_triad':

           237,436      branch-misses                                                         
        39,972,524      bus-cycles                                                            
         6,974,190      cache-misses                     #   74.62% of all cache refs         
         9,346,537      cache-references                                                      
     1,319,093,303      cpu-cycles                                                            
       886,769,321      instructions                     #    0.67  insn per cycle            

       0.402277715 seconds time elapsed

       0.163948000 seconds user
       0.237925000 seconds sys

Output after checking the performance for timestep_opt1.c

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ sudo perf stat -e branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions ./stream_triad
Minimum dt is 0.016964

 Performance counter stats for './stream_triad':

           266,973      branch-misses                                                         
        42,794,161      bus-cycles                                                            
         7,368,132      cache-misses                     #   71.78% of all cache refs         
        10,264,646      cache-references                                                      
     1,412,207,256      cpu-cycles                                                            
       883,883,675      instructions                     #    0.63  insn per cycle            

       0.431171959 seconds time elapsed

       0.174162000 seconds user
       0.256238000 seconds sys

Output after checking the performance for timestep_opt2.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ sudo perf stat -e branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions ./stream_triad
Minimum dt is 0.016964

 Performance counter stats for './stream_triad':

           244,176      branch-misses                                                         
        39,860,848      bus-cycles                                                            
         7,140,664      cache-misses                     #   76.37% of all cache refs         
         9,350,362      cache-references                                                      
     1,315,407,958      cpu-cycles                                                            
       886,026,023      instructions                     #    0.67  insn per cycle            

       0.403344476 seconds time elapsed

       0.156831000 seconds user
       0.243737000 seconds sys

Output after checking the perfomance for timestep_opt3.c:

student@itcenter-lab128:~/Desktop/ParallelPrograming-Assignments$ sudo perf stat -e branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions ./stream_triad
Minimum dt is 0.016964

 Performance counter stats for './stream_triad':

           270,482      branch-misses                                                         
        44,596,612      bus-cycles                                                            
         7,504,052      cache-misses                     #   70.78% of all cache refs         
        10,601,536      cache-references                                                      
     1,471,688,133      cpu-cycles                                                            
       886,822,605      instructions                     #    0.60  insn per cycle            

       0.461554755 seconds time elapsed

       0.159725000 seconds user
       0.288503000 seconds sys

For all optimized iterations, we have used vector width of 256 bits. 

timestep.c

This is not vectorized due to control flow and sqrt() causing memory clobbering. For this file the 256 bit vector width was not applied. IPC (instructions per cycle)= 0.67, showing no vectorization benefit.

timestep_opt1.c

This file is partially vectorized using 256 bit vectors. Some loops still missed due to control flow and sqrt(). IPC = 0.63 and the time took for running the program is 0.43s, which comes to conclusion that there is no speedup. 

timestep_opt2.c

Running this file, one loop was successfully vectorized, while others failed due to control flow and sqrt(). For this version we can say that its partially vectorized. Perfomance results show an IPC of 0.67 and the best runtime of 0.403s, making this optimization the best-performing run among the all tested runs. 

timestep_opt3.c 

This version vectorized most loops out of every other version, two loops were successfully vectorized. One was vectorized using 256 bit, and another one using 128 bit. This means that is mostly vectorized, using mixed vector lengths. The added compiler flags (-fno-trapping-math -fno-math-errno), helped the compiler successfully vectorize more loops. Despite the better vectorization coverage, the IPC dropped to 0.60 and runtime increased 0.46s, indicating that the added overhead or memory behavior offset the gains. 