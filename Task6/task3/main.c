#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv) {
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int result = N * M - 1;
    printf("\n%d\n", result);
    return 0;
}