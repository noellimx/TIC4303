this is for working reference


it is implied (malloc 256) / (line length =  16) = 16 byte per character




example run
gcc -Wall -fsanitize=address L1-eg.c L1-main.c && echo "abcdefghijklmnopqrstuvwxyz" | ./a.out
gcc -Wall -fsanitize=address L1-eg.c L1-main.c && echo "linesarealternatedbyinputanditsreverse" | ./a.out
linesarealternatedbyinputanditsreverse

# Notes

- sizeof has no idea of malloc (the programmer controls memory allocation!!!)
- ```gcc``` flag ```-fsanitize=address``` helps to check for memory leaks during runtime. i.e, if illegal value modification to other variable's or stack's heap memory



# submission


# compile and run

gcc -Wall -fsanitize=address lim-A0211270Y-lab1-ex2.c L1-main.c && echo "linesarealternatedbyinputanditsreverse" | ./a.out
gcc -Wall -fsanitize=address sim-a0211422b-lab1-ex2.c L1-main.c && echo "linesarealternatedbyinputanditsreverse" | ./a.out