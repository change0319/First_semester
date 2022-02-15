#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100
int main(void) {
	int mass_position[MAX_ARRAY_SIZE];
	FILE* keyboard;
	int num;
	int broken = 0;
	int amount = 0;
	int arr[MAX_ARRAY_SIZE];
	if (fopen_s(&keyboard, "D:\\yakaev1\\aud5\\task4\\keyboard.txt", "r") == 0) {
		fscanf_s(keyboard, "%d", &amount);
		for (int i = 0; i < amount; i++)
			fscanf_s(keyboard, "%d", &arr[i]);
	}
	for (int i = 0; i < amount; i++) {
		mass_position[i] = i;
	}
	for (int i = 0; i < amount; i++) {
		printf("%d ", mass_position[i]);
	}
	while ((fscanf_s(keyboard, "%d", &num) != EOF)) {
		arr[num - 1] -= 1;
	}
	for (int i = 0; i < amount; i++)
		if (arr[i] < 0)
			broken += 1;
	printf("\n");
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
				int q = mass_position[j];
				mass_position[j] = mass_position[j + 1];
				mass_position[j + 1] = q;
			}
		}
	}
	for (int i = 0; i < amount; i++)
		printf("%d ", mass_position[i]
		);
	printf("\n");
	printf("%d ", broken);
	return;
}