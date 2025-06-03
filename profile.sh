#!/bin/bash

source config

# clear


# perf stat $DIR_TARGET/PERF_CASE_STUDY.exe # nie dla WSL

# perf record -D 100 ./$DIR_TARGET/PERF_CASE_STUDY.exe 1000000 10000
# perf annotate -Mintel

clear_file "gprof_output.png"; clear_file "gmon.out"; clear_file "gprof_output.txt"; 
# gprof $DIR_TARGET/PERF_CASE_STUDY.exe gmon.out > gprof_output.txt
gprof $DIR_TARGET/PERF_CASE_STUDY.exe gmon.out | gprof2dot -w -s | dot -Tpng -o gprof_output.png

# 