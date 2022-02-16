#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
    int N = 0;
    scanf_s("%d", &N);
    int k = N;
    int size = 0;
    while (k > 0)
    {
        size++;
        k /= 10;
    }
    int* mass = (int)malloc(size * sizeof(int));
    for (int i = size - 1;i >= 0;i--) {
        mass[i] = N % 10;
        N /= 10;
    }
    int tmp = 0;
    for (int j = size - 1;j > 0;j--) {
        if (mass[j] < mass[j - 1]) {
            tmp = mass[j];
            mass[j] = mass[j - 1];
            mass[j - 1] = tmp;
            break;
        }
        else {
            printf("0");
            return 0;
        }
    }
    for (int i = 0;i < size;i++) {
        printf("%d", mass[i]);
    }
    return 0;
}