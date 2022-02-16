#include <stdlib.h>
#include <stdio.h>

int main() {
	int n;
	char symbol;
	int result = 1;
	int k = 0;
	char array[20];
	scanf_s("%d ", &n);
	while (1) {
		scanf_s("%c", &symbol, 1);
		if (symbol == '!') {
			k++;
		}
		else 
			break;
	}
	int j = n;
	for (j; j > 0; j -= k) {
		result *= j;
	}
	printf("%d", result);
	return 0;
}