#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
    int R;
    int mnim;
}complex;
int main(int argc, char* argv[]) {
    complex a, b, c;
    char bracket1, bracket2, comma1, comma2; char operation;
    scanf_s("%c%d%c%d%c %c %c%d%c%d%c", &bracket1, 1, &a.R, &comma1, 1, &a.mnim, &bracket2, 1, &operation, 1, &bracket1, 1, &b.R, &comma2, 1, &b.mnim, &bracket2, 1);
    switch (operation) {
    case '+':
        c.R = a.R + b.R;
        c.mnim = a.mnim + b.mnim;
        break;
    case '-':
        c.R = a.R - b.R;
        c.mnim = a.mnim - b.mnim;
        break;
    case '*':
        c.R = a.R * b.R - a.mnim * b.mnim;
        c.mnim = a.R * b.mnim + a.mnim * a.R;
        break;
    default:
        printf_s("ERROR: UNKNOWN OPERATION\n");
        return 1;
    }
    if (c.mnim < 0) {
        printf_s("(%d%di)\n", c.R, c.mnim);
    }
    else printf_s("(%d+%di)\n", c.R, c.mnim);
    if (argc != 11) {
        system("pause");
    }
    return 0;
}