# -Werror  -Wall  -Wextra -pedantic -fno-common   -Wno-error=format

g++   arm_math.h cmsis_gcc.h  main.cpp  wave.c  Acoustic_DB100.c cmsis_gcc.h -o  test.out

./test.out
