#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

int main(void) {
	FILE* keyboard;
	int num;
	int broken = 0;
	int amount = 0;
	int arr[MAX_ARRAY_SIZE];
	if (fopen_s(&keyboard, "keyboard.txt", "r") == 0) {
		fscanf_s(keyboard, "%d", &amount);
		for (int i = 0; i < amount; i++)
			fscanf_s(keyboard, "%d", &arr[i]);
	}
	while ((fscanf_s(keyboard, "%d", &num) != EOF)) {
		arr[num - 1] -= 1;
	}
	for (int i = 0; i < amount; i++)
		if (arr[i] < 0)
			broken += 1;
	printf("%d", amount);
	printf("\n");
	for (int i = 0; i < amount; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d ", broken);
	return;
}