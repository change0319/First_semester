#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 10

int main() {
	int arr[ARRAY_SIZE];
	setlocale(LC_ALL, ".1251");
	// заполнение массива случайными целыми числами из промежутка (-100, 100):
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr[i] = (rand() % 2 ? -1 : 1) * (rand() % 100);
	}
	int num;
	printf("Введите натуральное число: ");
	scanf_s("%d", &num);
	// проверка введённого числа на натуральность
	if (num <= 0) {
		printf("%d - не натуральное число", num);
		return 0;
	}
	// считает количество чисел которые делятся на num
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] % num == 0)
			counter += 1;
	}
	// создаю массив, выделяю память на определенное количество элементов
	int e = 0;
	int w = 0;
	int* divisible = (int*)malloc(counter * sizeof(int));
	int* undivisible = (int*)malloc((ARRAY_SIZE - counter) * sizeof(int));
	// числа кратные num добавляются в массив divisible
	for (int i = 0; i < ARRAY_SIZE; i++)
		if (arr[i] % num == 0) {
			divisible[w] = arr[i];
			w++;
		}
	// числа некратные num добавляются в массив undivisible
	for (int i = 0; i < ARRAY_SIZE; i++)
		if (arr[i] % num != 0) {
			undivisible[e] = arr[i];
			e++;
		}
	// сортировка пузырьком по убыванию массива divisible
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (divisible[j] < divisible[j + 1]) {
				int q = divisible[j];
				divisible[j] = divisible[j + 1];
				divisible[j + 1] = q;
			}
		}
	}
	// сортировка пузырьком по убыванию массива undivisible
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e - 1; j++) {
			if (undivisible[j] < undivisible[j + 1]) {
				int q = undivisible[j];
				undivisible[j] = undivisible[j + 1];
				undivisible[j + 1] = q;
			}
		}
	}
	// создаю новый массив, в который буду "переливать" массивы divisible и undivisible
	int Array[ARRAY_SIZE];
	int r = 0;
	int t = 0;
	// добавляю элементы массивов divisible и undivisible в массив Array[]
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (divisible[r] < undivisible[t]) {
			Array[i] = undivisible[t];
			t++;
		}
		else {
			Array[i] = divisible[r];
			r++;
		}
	}
	// вывожу три массива
	printf("\n");
	printf("Массив кратный %d: ", num);
	for (int i = 0; i < counter; i++)
		printf("%d ", divisible[i]);
	printf("\n\n");
	printf("Массив некратный %d: ", num);
	for (int i = 0; i < ARRAY_SIZE - counter; i++)
		printf("%d ", undivisible[i]);
	printf("\n\n");
	printf("Объединение двух массивов: ");
	for (int i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", Array[i]);
	printf("\n\n");
	free(divisible);
	free(undivisible);
	return 0;
}