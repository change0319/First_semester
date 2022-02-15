#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 10

int main() {
	int arr[ARRAY_SIZE];
	setlocale(LC_ALL, ".1251");
	// ���������� ������� ���������� ������ ������� �� ���������� (-100, 100):
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr[i] = (rand() % 2 ? -1 : 1) * (rand() % 100);
	}
	int num;
	printf("������� ����������� �����: ");
	scanf_s("%d", &num);
	// �������� ��������� ����� �� �������������
	if (num <= 0) {
		printf("%d - �� ����������� �����", num);
		return 0;
	}
	// ������� ���������� ����� ������� ������� �� num
	int counter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] % num == 0)
			counter += 1;
	}
	// ������ ������, ������� ������ �� ������������ ���������� ���������
	int e = 0;
	int w = 0;
	int* divisible = (int*)malloc(counter * sizeof(int));
	int* undivisible = (int*)malloc((ARRAY_SIZE - counter) * sizeof(int));
	// ����� ������� num ����������� � ������ divisible
	for (int i = 0; i < ARRAY_SIZE; i++)
		if (arr[i] % num == 0) {
			divisible[w] = arr[i];
			w++;
		}
	// ����� ��������� num ����������� � ������ undivisible
	for (int i = 0; i < ARRAY_SIZE; i++)
		if (arr[i] % num != 0) {
			undivisible[e] = arr[i];
			e++;
		}
	// ���������� ��������� �� �������� ������� divisible
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (divisible[j] < divisible[j + 1]) {
				int q = divisible[j];
				divisible[j] = divisible[j + 1];
				divisible[j + 1] = q;
			}
		}
	}
	// ���������� ��������� �� �������� ������� undivisible
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < e - 1; j++) {
			if (undivisible[j] < undivisible[j + 1]) {
				int q = undivisible[j];
				undivisible[j] = undivisible[j + 1];
				undivisible[j + 1] = q;
			}
		}
	}
	// ������ ����� ������, � ������� ���� "����������" ������� divisible � undivisible
	int Array[ARRAY_SIZE];
	int r = 0;
	int t = 0;
	// �������� �������� �������� divisible � undivisible � ������ Array[]
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
	// ������ ��� �������
	printf("\n");
	printf("������ ������� %d: ", num);
	for (int i = 0; i < counter; i++)
		printf("%d ", divisible[i]);
	printf("\n\n");
	printf("������ ��������� %d: ", num);
	for (int i = 0; i < ARRAY_SIZE - counter; i++)
		printf("%d ", undivisible[i]);
	printf("\n\n");
	printf("����������� ���� ��������: ");
	for (int i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", Array[i]);
	printf("\n\n");
	free(divisible);
	free(undivisible);
	return 0;
}