==18554== Memcheck, a memory error detector
==18554== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==18554== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==18554== Command: build/bin/fdf resources/maps/42.fdf
==18554== 
==18554== 
==18554== HEAP SUMMARY:
==18554==     in use at exit: 109,475 bytes in 108 blocks
==18554==   total heap usage: 639 allocs, 531 frees, 152,026 bytes allocated
==18554== 
==18554== LEAK SUMMARY:
==18554==    definitely lost: 0 bytes in 0 blocks
==18554==    indirectly lost: 0 bytes in 0 blocks
==18554==      possibly lost: 0 bytes in 0 blocks
==18554==    still reachable: 109,475 bytes in 108 blocks
==18554==         suppressed: 0 bytes in 0 blocks
==18554== Rerun with --leak-check=full to see details of leaked memory
==18554== 
==18554== For lists of detected and suppressed errors, rerun with: -s
==18554== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 1)
