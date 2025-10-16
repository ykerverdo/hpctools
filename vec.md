cc -O3 -ftree-vectorize -fopt-info-vec-all   -c -o dgesv.o dgesv.c
dgesv.c:8:3: optimized: loop vectorized using 16 byte vectors
dgesv.c:8:3: optimized:  loop versioned for vectorization because of possible aliasing
dgesv.c:7:5: note: vectorized 1 loops in function.
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:27: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:27: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:8:3: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:3: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:13:10: note: ***** Analysis failed with vector mode VOID
dgesv.c:52:3: missed: couldn't vectorize loop
dgesv.c:52:3: missed: not vectorized: multiple nested loops.
dgesv.c:53:5: missed: couldn't vectorize loop
dgesv.c:53:5: missed: not vectorized: control flow in loop.
dgesv.c:54:7: missed: couldn't vectorize loop
dgesv.c:55:21: missed: not vectorized: complicated access pattern.
dgesv.c:39:5: missed: couldn't vectorize loop
dgesv.c:39:5: missed: not vectorized: loop nest containing two or more consecutive inner loops cannot be vectorized
dgesv.c:39:5: missed: couldn't vectorize loop
dgesv.c:39:5: missed: not vectorized: loop nest containing two or more consecutive inner loops cannot be vectorized
dgesv.c:45:7: optimized: loop vectorized using 16 byte vectors
dgesv.c:45:7: optimized:  loop versioned for vectorization because of possible aliasing
dgesv.c:42:7: optimized: loop vectorized using 16 byte vectors
dgesv.c:42:7: optimized:  loop versioned for vectorization because of possible aliasing
dgesv.c:8:3: optimized: loop vectorized using 16 byte vectors
dgesv.c:8:3: optimized:  loop versioned for vectorization because of possible aliasing
dgesv.c:8:3: optimized: loop vectorized using 16 byte vectors
dgesv.c:8:3: optimized:  loop versioned for vectorization because of possible aliasing
dgesv.c:23:5: missed: couldn't vectorize loop
dgesv.c:16:5: missed: not vectorized: unsupported use in stmt.
dgesv.c:23:5: note: ***** Analysis failed with vector mode V2DF
dgesv.c:23:5: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:16:5: note: vectorized 4 loops in function.
dgesv.c:18:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:23:5: note: ***** Analysis failed with vector mode V2DF
dgesv.c:23:5: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:25:10: note: ***** Analysis failed with vector mode V2DF
dgesv.c:25:10: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:23:5: note: ***** Analysis failed with vector mode VOID
dgesv.c:32:8: note: ***** Analysis failed with vector mode VOID
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:27: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:27: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:8:3: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:3: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:37:12: note: ***** Analysis failed with vector mode V2DF
dgesv.c:37:12: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:10:40: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:8:27: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:27: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:8:3: note: ***** Analysis failed with vector mode V2DF
dgesv.c:8:3: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:37:12: note: ***** Analysis failed with vector mode V2DF
dgesv.c:37:12: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:39:5: note: ***** Analysis failed with vector mode VOID
dgesv.c:46:34: note: ***** Analysis failed with vector mode VOID
dgesv.c:41:16: note: ***** Analysis failed with vector mode V2DF
dgesv.c:41:16: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:41:16: note: ***** Analysis failed with vector mode VOID
dgesv.c:42:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:42:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:42:27: note: ***** Analysis failed with vector mode V2DF
dgesv.c:42:27: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:42:7: note: ***** Analysis failed with vector mode V2DF
dgesv.c:42:7: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:45:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:39:5: note: ***** Analysis failed with vector mode VOID
dgesv.c:46:21: note: ***** Analysis failed with vector mode VOID
dgesv.c:46:21: note: ***** Analysis failed with vector mode VOID
dgesv.c:45:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:45:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:45:28: note: ***** Analysis failed with vector mode V2DF
dgesv.c:45:28: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:45:7: note: ***** Analysis failed with vector mode V2DF
dgesv.c:45:7: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:52:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:60:10: note: ***** Analysis failed with vector mode VOID
dgesv.c:53:14: note: ***** Analysis failed with vector mode VOID
dgesv.c:54:7: note: ***** Analysis failed with vector mode VOID
dgesv.c:53:5: note: ***** Analysis failed with vector mode V2DF
dgesv.c:53:5: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:52:3: note: ***** Analysis failed with vector mode VOID
dgesv.c:55:21: note: ***** Analysis failed with vector mode V2DF
dgesv.c:55:21: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
dgesv.c:54:7: note: ***** Analysis failed with vector mode V2DF
dgesv.c:54:7: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
cc -O3 -ftree-vectorize -fopt-info-vec-all   -c -o timer.o timer.c
timer.c:6:58: note: ***** Analysis failed with vector mode V2DI
timer.c:6:58: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DI
timer.c:13:62: note: ***** Analysis failed with vector mode V2DI
timer.c:13:62: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DI
timer.c:20:60: note: ***** Analysis failed with vector mode V2DI
timer.c:20:60: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DI
timer.c:27:54: note: ***** Analysis failed with vector mode V2DI
timer.c:27:54: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DI
cc -O3 -ftree-vectorize -fopt-info-vec-all   -c -o main.o main.c
main.c:19:5: missed: couldn't vectorize loop
main.c:20:19: missed: statement clobbers memory: _4 = rand ();
main.c:12:11: note: vectorized 0 loops in function.
main.c:15:33: missed: statement clobbers memory: matrix_16 = malloc (_3);
main.c:15:33: note: ***** Analysis failed with vector mode VOID
main.c:17:5: missed: statement clobbers memory: srand (seed_17(D));
main.c:19:5: note: ***** Analysis failed with vector mode VOID
main.c:20:19: missed: statement clobbers memory: _4 = rand ();
main.c:19:5: note: ***** Analysis failed with vector mode V2DF
main.c:19:5: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
main.c:23:12: note: ***** Analysis failed with vector mode VOID
main.c:28:34: missed: statement clobbers memory: replica_8 = malloc (_3);
main.c:28:34: note: ***** Analysis failed with vector mode VOID
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/string_fortified.h:34:10: missed: statement clobbers memory: __builtin_memcpy (replica_8, orig_9(D), _4);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/string_fortified.h:34:10: note: ***** Analysis failed with vector mode VOID
main.c:32:12: note: ***** Analysis failed with vector mode VOID
main.c:38:24: note: ***** Analysis failed with vector mode VOID
main.c:47:38: missed: couldn't vectorize loop
main.c:47:38: missed: not vectorized: control flow in loop.
main.c:42:16: note: vectorized 0 loops in function.
main.c:46:5: note: ***** Analysis failed with vector mode VOID
main.c:47:10: note: ***** Analysis failed with vector mode V2DF
main.c:47:10: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
main.c:46:5: note: ***** Analysis failed with vector mode VOID
main.c:46:5: note: ***** Analysis failed with vector mode VOID
main.c:47:38: missed: couldn't vectorize loop
main.c:47:38: missed: not vectorized: control flow in loop.
main.c:54:7: note: vectorized 0 loops in function.
main.c:56:8: note: ***** Analysis failed with vector mode VOID
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __builtin_puts (&"You need to provide a matrix size (e.g. 1024 for use 1024x1024 matrices)"[0]);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/stdlib.h:363:16: missed: statement clobbers memory: _32 = strtol (_1, 0B, 10);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/stdlib.h:363:16: note: ***** Analysis failed with vector mode V2DI
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/stdlib.h:363:16: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DI
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __printf_chk (1, "Matrix size: %dx%d\n", _33, _33);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: note: ***** Analysis failed with vector mode VOID
main.c:67:9: missed: statement clobbers memory: a_13 = generate_matrix (size.0_2, 1);
main.c:67:9: note: ***** Analysis failed with vector mode VOID
main.c:68:9: missed: statement clobbers memory: b_15 = generate_matrix (size.0_2, 2);
main.c:69:12: missed: statement clobbers memory: aref_17 = duplicate_matrix (a_13, size.0_2);
main.c:70:12: missed: statement clobbers memory: bref_19 = duplicate_matrix (b_15, size.0_2);
main.c:77:25: missed: statement clobbers memory: ipiv_21 = malloc (_4);
main.c:77:25: note: ***** Analysis failed with vector mode VOID
main.c:80:5: missed: statement clobbers memory: clock_gettime (1, &start);
main.c:82:12: missed: statement clobbers memory: LAPACKE_dgesv (101, _33, _33, aref_17, _33, ipiv_21, bref_19, _33);
main.c:84:5: missed: statement clobbers memory: clock_gettime (1, &now);
main.c:85:5: missed: statement clobbers memory: _5 = diff_milli (&start, &now);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __printf_chk (1, "Time taken by Lapacke dgesv: %ld ms\n", _5);
main.c:91:5: missed: statement clobbers memory: clock_gettime (1, &start);
main.c:93:12: missed: statement clobbers memory: my_dgesv (_33, _33, a_13, b_15);
main.c:95:5: missed: statement clobbers memory: clock_gettime (1, &now);
main.c:96:5: missed: statement clobbers memory: _6 = diff_milli (&start, &now);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __printf_chk (1, "Time taken by my dgesv solver: %ld ms\n", _6);
main.c:46:5: note: ***** Analysis failed with vector mode VOID
main.c:47:10: note: ***** Analysis failed with vector mode V2DF
main.c:47:10: note: ***** Skipping vector mode V16QI, which would repeat the analysis for V2DF
main.c:46:5: note: ***** Analysis failed with vector mode VOID
main.c:54:7: note: ***** Analysis failed with vector mode VOID
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __builtin_puts (&"Result is ok!"[0]);
/mnt/netapp1/Optcesga_FT2_RHEL7/2020/gentoo/22072020/usr/include/bits/stdio2.h:107:10: missed: statement clobbers memory: __builtin_puts (&"Result is wrong!"[0]);
cc -o dgesv_v3 dgesv.o timer.o main.o -lopenblas