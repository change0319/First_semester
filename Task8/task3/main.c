#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int gorizontal[8];
    int vertical[8];
    for (int i = 0;i < 8;i++) {
        gorizontal[i] = 0;
        vertical[i] = 0;
    }
    for (int i = 0;i < 8;i++) {
        scanf_s("%d", &gorizontal[i]);
        scanf_s("%d", &vertical[i]);
        printf("(%d;%d)", gorizontal[i], vertical[i]);
    }
    int count = 0;
    for (int i = 0;i < 8;i++) {
        for (int j = i + 1;j < 8;j++) {
            if (gorizontal[i] == gorizontal[j])
                count += 1;
            else if (vertical[i] == vertical[j])
                count += 1;
            else if (abs(vertical[i] - vertical[j]) == abs(gorizontal[j] - gorizontal[i]))
                count += 1;
            else if (abs(vertical[j] - vertical[i]) == abs(gorizontal[i] - gorizontal[j]))
                count += 1;
        }
    }
    if (count != 0) {
        printf("\nNo.");
    }
    else {
        printf("\nYes!");
    }
    return 0;
}