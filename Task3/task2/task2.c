#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* input, *result;
	int arr[3];
	int length = 0;
	if (fopen_s(&input, "input.txt", "r") == 0) {
		for (int i = 0; i < 3; i++)
			fscanf_s(input, "%d", &arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr[j] > arr[j + 1]) {
				int k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
	if (arr[0] + arr[1] <= arr[2]) {
		length = arr[2] - (arr[0] + arr[1])+1;
	}
	if (fopen_s(&result, "D:\\yakaev1\\aud5\\task2\\result.txt", "w+") == 0) {
		fprintf(result, "%d", length);
	}
	system("pause");
	return 0;
}