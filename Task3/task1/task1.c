#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
#define INPUT_FILE_NAME "numbers"
#define OUTPUT_FILE_NAME "sorted"

void sort(int[MAX_ARRAY_SIZE], int numbersCount);

int main(void) {
	int numbersCount;
	printf("Input the number of elements of the array less than 100: ");
	scanf_s("%d", &numbersCount);
	if (numbersCount > 100) {
		printf("You must input number less than 100.");
		printf("\n");
		return;
	}
	FILE* input, * output;
	int arr[MAX_ARRAY_SIZE];
	int i = 0;
	if (fopen_s(&input, "input.txt", "w+") == 0) {
		while (i < numbersCount)
		{
			fprintf_s(input, "%d ", rand() % 100);
			++i;
		}
		fseek(input, 0, SEEK_SET);
		for (int j = 0; j < numbersCount; j++) {
			fscanf_s(input, "%d", &arr[j]);
		}
		fclose(input);
	}
	sort(arr,numbersCount);
	if (fopen_s(&output, "output.txt", "w+") == 0) {
		for (int j = 0; j < numbersCount; j++)
			fprintf(output, "%d ", arr[j]);
		fclose(output);
	}
	system("pause");
	return 0;
}

void sort(int arr[MAX_ARRAY_SIZE], int numbersCount) {
	for (int i = 0; i < numbersCount; i++) {
		for (int j = 0; j < numbersCount - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int q = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = q;
			}
		}
	}
}