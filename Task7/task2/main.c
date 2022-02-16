#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int arr[10];
    for (int i = 0;i < 10;i++) {
        arr[i] = 0;
    }
    int k = atoi(argv[1]);
    srand(time(0));
    int* array = (int*)malloc(k*sizeof(int));
    for (int i = 0;i < k;i++) {
        array[i] = rand();
    }
    for (int j = 2;j <= 9;j++) {
        for (int i = 0;i < k;i++) {
            if (array[i] % 10 == j) {
                arr[j]++;
            }
        }
    }
    int sum=0;
    for (int i = 2;i <= 9;i++) {
        sum += arr[i];
    }
    if (k > 1000) {
        for (int i = 2;i <= 9;i++) {
            arr[i] =arr[i]%100 ;
        }
    }
    
    for (int j = 2;j <= 9;j++) {
        printf("%d:",j);
        int k = arr[j];
        for (int i = 0;i < k;i++) {
            printf("~");
        }
        printf("\n\n");
    }
    free(array);
    return 0;
}