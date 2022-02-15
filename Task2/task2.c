#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, ".1251");
	int Array[10];
	printf("¬ведите 10 целых чисел:");
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &Array[i]);
	printf("\n");
	for (int i = 0; i < 10; i++) {
		if (Array[i] > 0)
			printf("%d ", Array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}