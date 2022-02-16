#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
void gotoxy(int column, int row)
{
    HANDLE hCons;
    COORD crd;
    hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    crd.X = (short)column;
    crd.Y = (short)row;
    SetConsoleCursorPosition(hCons, crd);

}
void oblako(int size) {
    for (int j = 0;j < 3;j++) {
        for (int i = 0;i < 5;i++) {
            gotoxy(size + i, j);
            printf(" ");
            Sleep(5);
        }
    }
}
void elka(HANDLE h) {
    SetConsoleTextAttribute(h, BACKGROUND_RED);
    for (int i = 0;i < 3;i++) {
        gotoxy(11, 15 + i);
        printf("  \n");
    }
    SetConsoleTextAttribute(h, BACKGROUND_GREEN);
    for (int i = 0;i < 14;i++) {
        gotoxy(5 + i, 15);
        printf(" ");
    }
    for (int i = 0;i < 7;i++) {
        gotoxy(5 + i, 14 - i);
        printf(" ");
    }
    for (int i = 0;i < 7;i++) {
        gotoxy(12 + i, 8 + i);
        printf(" ");
    }

    for (int i = 0;i < 7;i++) {
        int j = 0;
        if (i < 7) {
            while (j != i + 1) {
                gotoxy(6 + i, 14 - j);
                printf(" ");
                j++;

            }
        }
    }
    for (int i = 0;i < 7;i++) {
        int j = 0;
        if (i < 7) {
            while (j != i + 1) {
                gotoxy(18 - i, 14 - j);
                printf(" ");
                j++;

            }
        }
    }
    for (int i = 0;i < 300;i++) {
        //7,16 5,13, 4,5
        if (i % 3 == 0) {
            SetConsoleTextAttribute(h, BACKGROUND_RED);
        }
        else if (i % 4 == 0) {
            SetConsoleTextAttribute(h, BACKGROUND_BLUE);
        }
        else if (i % 5 == 0) {
            SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_RED);
        }
        gotoxy(16, 13);
        printf(" ");
        gotoxy(12,10);
        printf(" ");
        gotoxy(10, 13);
        printf(" ");
        gotoxy(9,14);
        printf(" ");
        Sleep(150);
    }
}
int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_BLUE);
    oblako(0);
    oblako(10);
    oblako(20);
    elka(h);
    gotoxy(0, 50);
    return 0;
}