#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, ".1251");
	int Array[10];
	int pArray[5];
	printf_s("¬ведите 10 целых чисел: ");
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &Array[i]);
	printf("\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (Array[j] > Array[j + 1]) {
				int q = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = q;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		pArray[i] = Array[i + 5];
		printf("%d ", pArray[i]);
	}
	system("pause");
	return 0;
}