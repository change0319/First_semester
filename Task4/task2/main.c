#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    char** str = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        str[i] = (char*)malloc((M + 1) * sizeof(char));
        gets(str[i]);
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < strlen(str[i]) - 2;j++) {
            char tmp = str[i][j];
            str[i][j] = str[i][strlen(str[i]) - 1 - j];
            str[i][strlen(str[i])-1 - j] = tmp;
        }
    }
    printf("\n");
    for (int i = 0;i < N;i++) {
        if (strlen(str[i]) > M) {
            printf("%s - length is greater than maximum\n", str[i]);
            continue;
        }
        else if (str[i] != NULL || strlen(str[i]) <= M) {
            printf("%s (len = % d)\n", str[i], strlen(str[i]));
        }
    }
    for (int i = 0; i < N; i++)
        free(str[i]);
    free(str);
    return 0;
}
