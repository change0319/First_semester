#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N, M;
    scanf_s("%d", &N);
    scanf_s("%d ", &M);
    char** str = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        str[i] = (char*)malloc((M + 1) * sizeof(char));
        gets(str[i]);
    }
    printf("\n");
    for (int i = 0;i < N ;i++) {
        if (strlen(str[i]) > M) {
            printf("%s - length is greater than maximum\n", str[i]);
            continue;
        }
        else if (str[i] != NULL || strlen(str[i]) <= M)
            printf("%s (len = % d)\n",str[i], strlen(str[i]));
    }
    for (int i = 0; i < N; i++)
        free(str[i]);
    free(str);
    return 0;
}