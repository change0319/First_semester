#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>

int openfile(char* name, int* arr) {
    setlocale(LC_ALL, "Russian");
    arr[2];
    char symbol;
    int str = 0;
    int columns = 0;
    int checker = 0;
    FILE* input;
    if (fopen_s(&input, name, "r")) {
        perror("");
        exit(0);
    }
    else {
        do {
            fscanf_s(input, "%c", &symbol, 1);
            columns++;
            if (symbol == ' ')
                columns--;
        } while (symbol != '\n');
        columns--;
        fseek(input, 0, SEEK_SET);
        while (fscanf_s(input, "%c", &symbol, 1) != EOF) {
            checker++;
            if (symbol == ' ')
                checker--;
            if (symbol == '\n') {
                checker--;
                if (columns != checker) {
                    printf("Неверный тип матрицы.\n");
                    exit(0);
                }
                checker = 0;
                str++;
            }
        }
        fseek(input, 0, SEEK_SET);
        while (fscanf_s(input, "%c", &symbol, 1) != EOF) {
            if (symbol == '\n' || symbol == ' ') {
                continue;
            }
            if (symbol < '0' || symbol>'9') {
                printf("\nerr\n");
                exit(0);
            }
        }
        printf("%d x %d ... %d\n", columns, str, checker);
        printf("\n");
    }
    fclose(input);
    arr[0] = str;
    arr[1] = columns;
    return 0;
}

int** matr_to_arr(char* name, int row, int column, int** array) {
    FILE* input;
    fopen_s(&input, name, "r");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            fscanf_s(input, "%d", &array[i][j]);
        }
    }
    fclose(input);
    return 0;
}
void printit(int** arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int MainMenu() {
    errno = 0;
    int size1[2];
    int size2[2];
    char* name = { "mat1.txt" };
    char* name1 = { "mat2.txt" };
    openfile(name, size1);
    openfile(name1, size2);
    if (errno != 0)
        return 1;
    system("cls");
    printf("\n");
    int** array1 = (int**)malloc(sizeof(int*) * size1[0]);
    for (int i = 0; i < size1[0]; i++) {
        array1[i] = (int*)malloc(sizeof(int*) * size1[1]);
    }
    int** array2 = (int**)malloc(sizeof(int*) * size2[0]);
    for (int i = 0; i < size2[0]; i++) {
        array2[i] = (int*)malloc(sizeof(int*) * size2[1]);
    }
    matr_to_arr(name, size1[0], size1[1], array1);
    matr_to_arr(name1, size2[0], size2[1], array2);
    printit(array1, size1[0], size1[1]);
    printf("\n");
    printit(array2, size2[0], size2[1]);
    setlocale(LC_ALL, "Russian");
    printf("Выберите операцию:\n");
    printf("1)Сложение двух матриц.\n");
    printf("2)Вычитание одной матрицы из другой.\n");
    printf("3)Перемножение двух матриц.\n");
    printf("4)Транспонирование матрицы.\n");
    printf("5)Нахождение определителя матрицы.\n");
    while (!_kbhit());
    char numbers = _getch();
    system("cls");
    int checker = 0;
    switch (numbers) {
    case '1':
        if (size1[0] != size2[0] || size1[1] != size2[1]) {
            printf("\nЭти матрицы нельзя сложить друг с другой\n");
            exit(0);
        }
        else {
            plus(array1, array2, size1[0], size1[1]);
            printf("1)Выход в главное меню.\n2)Выход из программы.\n");
            scanf_s("%d", &checker);
            if (checker == 1) {
                MainMenu();
            }
            else
                exit(0);

            break;
        }
    case '2':
        if (size1[0] != size2[0] || size1[1] != size2[1]) {
            printf("\nЭти матрицы нельзя вычитать.\n");
            exit(0);
        }
        else {
            minus(array1, array2, size1[0], size1[1]);
            printf("1)Выход в главное меню.\n2)Выход из программы.\n");
            scanf_s("%d", &checker);
            if (checker == 1) {
                MainMenu();
            }
            else
                exit(0);
            break;
        }
    case '3':
        multiply(array1, array2, size1[0], size1[1], size2[0], size2[0]);
        printf("1)Выход в главное меню.\n2)Выход из программы.\n");
        scanf_s("%d", &checker);
        if (checker == 1) {
            MainMenu();
        }
        else
            exit(0);
        break;
    case '4':
        trans(array1, array2, size1[0], size1[1], size2[0], size2[0]);
        printf("1)Выход в главное меню.\n2)Выход из программы.\n");
        scanf_s("%d", &checker);
        if (checker == 1) {
            MainMenu();
        }
        else
            exit(0);
        break;
    case '5':
        determinate(array1, size1[0]);
        break;
    default:
        printf("Неверно выбрана операция.");
        break;
    }
    for (int i = 0; i < size1[0]; i++)
        free(array1[i]);
    free(array1);
    for (int i = 0; i < size2[0]; i++)
        free(array2[i]);
    free(array2);
    return 1;
}


int plus(int** mat1, int** mat2, int row, int column) {
    int** result = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        result[i] = (int*)malloc(sizeof(int*) * column);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printit(result, row, column);
    for (int i = 0; i < row; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}


int minus(int** mat1, int** mat2, int row, int column) {
    printf("1)Вычесть первую матрицу из второй.\n2)Вычесть вторую матрицу из первой.\n");
    char num = _getch();
    system("cls");
    int** result = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        result[i] = (int*)malloc(sizeof(int*) * column);
    }
    switch (num) {
    case '1':
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                result[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        printit(result, row, column);
        break;
    case '2':
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                result[i][j] = mat2[i][j] - mat1[i][j];
            }
        }
        printit(result, row, column);
        for (int i = 0; i < row; i++) {
            free(result[i]);
        }
        free(result);
        break;
    }
    return 0;
}

int multiply(int** mat1, int** mat2, int row1, int column1, int row2, int column2) {
    int** result = (int**)malloc(sizeof(int*) * row1);
    for (int i = 0; i < row1; i++) {
        result[i] = (int*)malloc(sizeof(int*) * column2);
    }
    if (column1 == row2) {
        for (int i = 0;i < row1;i++) {
            for (int j = 0;j < column1;j++) {
                result[i][j] = 0;
                for (int k = 0;k < column1;k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
    else {
        printf("\nКоличество столбцов первой матрицы не равно количеству строк второй.\n");
        exit(0);
    }
    printit(result, row1, column2);
    for (int i = 0; i < row1; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}

int trans(int** mat1, int** mat2, int row1, int column1, int row2, int column2) {
    printf("\n1)Транспонировать первую матрицу.\n2)Транспонировать вторую матрицу.");
    char num = _getch();
    system("cls");
    if (num == '1') {
        int** result = (int**)malloc(sizeof(int*) * column1);
        for (int i = 0; i < column1; i++) {
            result[i] = (int*)malloc(sizeof(int) * column1);
        }
        for (int i = 0;i < row1;i++) {
            for (int j = 0;j < column1;j++) {
                result[j][i] = mat1[i][j];
            }
        }
        printit(result, column1, row1);
        for (int i = 0; i < row1; i++) {
            free(result[i]);
        }
        free(result);
    }
    if (num == '2') {
        int** result = (int**)malloc(sizeof(int*) * column2);
        for (int i = 0; i < column2; i++) {
            result[i] = (int*)malloc(sizeof(int*) * column2);
        }
        for (int i = 0;i < row2;i++) {
            for (int j = 0;j < column2;j++) {
                result[j][i] = mat2[i][j];
            }
        }
        printit(result, column2, row2);
        for (int i = 0; i < row2; i++) {
            free(result[i]);
        }
        free(result);
    }
    return 0;
}
int determinate(int** mat1, int row1) {
    int z = 0;
    printf("\n1)Найти определитель первой матрицы.\n2)Найти определитель второй матрицы.\n");
    int det = 0;
    char num = _getch();
    system("cls");
    int i,j, d, k, n;
    int** mass = (int**)malloc(sizeof(int*) * row1);
    for (int x = 0; i < row1; i++) {
        mass[i] = (int*)malloc(sizeof(int*) * row1);
    }
    j = 0;
    d = 0;
    k = 1;
    n = row1 - 1;
    if (num == 1) {
        if (row1 == 1) {
            det = mat1[0][0];
        }
        if (row1 == 2) {
            for (int x = 0;i < row1;i++) {
                det = mat1[0][0] * mat1[1][1] - mat1[0][1] * mat1[1][0];
            }
        }
        if (row1 > 2) {
            for (int i = 0;i < row1;i++) {
                get_dop_matr(mat1,mass,i,z,row1);
                d = d + k * mat1[i][0] * determinate(mass,n);
                k = -k;
            }
        }
        else {
            printf("\nМатрица должна быть квадратной.\n");
        }
    }
    printf("%d\n", d);
    printf("determinate");
    return 0;
}
void get_dop_matr(int** mass,int **arr,int i,int j,int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0;ki < m - 1;ki++) {
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0;kj < m - 1;kj++) {
            if (kj == j)
                dj = 1;
            arr[ki][kj] = mass[ki + di][kj+di];
        }
    }
}