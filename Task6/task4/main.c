#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
    int mass[100] = { 0 };
    int N = atoi(argv[1]);
    int* arr = (int*)malloc((argc - 2) * sizeof(int));
    for (int i = 0;i < argc-2;i++) {
        arr[i] = i;
    }

    printf("\n");
    if (N > (argc - 2)) {
        printf("ERROR\n");
        return 1;
    }
    for (int i = 0;i < argc-2;i++) {
        mass[i] = strlen(argv[i+2]);
    }
    int max = 0;
    for (int i = 2;i < argc;i++) {
        if (mass[i] > max)
            max = mass[i];
    }
    for (int i = 0; i < argc - 2; i++) {
        for (int j = 0; j < argc-3; j++) {
            if (mass[j] < mass[j + 1]) {
                int tmp1 = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp1;
                int tmp2 = arr[j];
                arr[j] = arr[j + 1];
                arr[j +1] = tmp2;
            }
        }
    }
    printf("\n");
    int* arr1 = (int*)malloc(N * sizeof(int));
    for (int i = 0;i < N;i++) {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int tmp3 = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = tmp3;
            }
        }
    }
    for (int i = 0;i < N;i++) {
        printf("%s ",argv[arr1[i]+2] );
    }
    free(arr);
    free(arr1);
    return 0;
}