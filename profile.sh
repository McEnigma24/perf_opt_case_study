#!/bin/bash

source config

# clear


# perf stat $DIR_TARGET/PERF_CASE_STUDY.exe # nie dla WSL

clear_file "gprof_output.png"; clear_file "gmon.out"; clear_file "gprof_output.txt"; 
# gprof $DIR_TARGET/PERF_CASE_STUDY.exe gmon.out > gprof_output.txt
gprof $DIR_TARGET/PERF_CASE_STUDY.exe gmon.out | gprof2dot -w -s | dot -Tpng -o gprof_output.png

# 