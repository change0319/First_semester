#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void binary_representation(int num, int* Arr);
int summ(int num);
int input();
void output(int* Arr);

int main(void) {
	printf("Hey!\nPlease enter the name of the first file: ");
	int sum, Array[32], num = input();
	errno = 0;
	if (errno != 0)
		return 1;
	sum = summ(num);
	binary_representation(num, Array);
	printf("Please enter the name of the second file: ");
	output(Array);
	printf("Sum of digits of a number: %d\n", sum);
	system("pause");
	return 0;
}

int input() {
	char max[10] = { '2','1','4','7','4','8','3','6','4','7' };
	char min[10] = { '2','1','4','7','4','8','3','6','4','8' };
	int count = 0;
	char symbol;
	int number = 0;
	char in_text[100] = { 0 };
	FILE* input;
	gets(in_text);
	if (fopen_s(&input, in_text, "r")) {
		perror("");
		exit(0);
	}
	else {
		fscanf_s(input, "%d", &number);
		fseek(input, 0, SEEK_SET);
		fscanf_s(input, "%c", &symbol, 1);
		if (symbol != '-')
			fseek(input, 0, SEEK_SET);
		while (fscanf_s(input, "%c", &symbol, 1) != EOF) {
			count++;
			if (symbol < '0' || symbol>'9') {
				printf("There is no number in the file!\n");
				exit(0);
			}
		}
		fseek(input, 0, SEEK_SET);
		if (count == 0) {
			printf("There is nothing in the file!\n");
			exit(0);
		}
		if (count > 10) {
			printf("The number exceeds the maximum!\n");
			exit(0);
		}
		else if (count == 10) {
			fseek(input, 0, SEEK_SET);
			fscanf_s(input, "%c", &symbol, 1);
			if (symbol == '-') {
				for (int i = 0; i < 10; i++) {
					fscanf_s(input, "%c", &symbol, 1);
					if (symbol < min[i]) {
						break;
					}
					if (symbol == min[i]) {
						continue;
					}
					if (symbol > min[i]) {
						printf("Negative number exceeds maximum!\n");
						exit(0);
					}
				}
			}
			else {
				fseek(input, 0, SEEK_SET);
				for (int i = 0; i < 10; i++) {
					fscanf_s(input, "%c", &symbol, 1);
					if (symbol < max[i]) {
						break;
					}
					if (symbol == max[i]) {
						continue;
					}
					if (symbol > max[i]) {
						printf("The number exceeds the maximum!\n");
						exit(0);
					}
				}
			}
		}
		fclose(input);
		return number;
	}
}

int summ(int num) {
	int sum = 0;
	while (num != 0) {
		sum = sum + num % 10;
		num /= 10;
	}
	sum = abs(sum);
	return sum;
}

void binary_representation(int num, int* Arr) {
	if (num < 0) {
		num = abs(num);
		Arr[0] = 1;
	}
	else
		Arr[0] = 0;
	//двоичное представление числа
	for (int i = 31; i > 0; i--)
	{
		Arr[i] = num % 2;
		num = num / 2;
	}
	if (Arr[0] == 1) {
		// обратный код числа
		for (int i = 1; i < 32; i++) {
			if (Arr[i] == 0)
				Arr[i]++;
			else Arr[i]--;
		}
		// доп код числа
		for (int i = 31; i > 0; i--) {
			if (Arr[i] == 0) {
				Arr[i] = 1;
				break;
			}
			else
				Arr[i] = 0;
		}
	}
}

void output(int* Arr) {
	char out_text[100] = { 0 };
	FILE* output;
	gets(out_text);
	if (fopen_s(&output, out_text, "w")) {
		perror("");
	}
	else {
		printf("Binary representation of a number: ");
		printf("\n");
		for (int i = 0; i < 32; i++) {
			printf("%d", Arr[i]);
			fprintf(output, "%d", Arr[i]);
			if (i % 4 == 3) {
				fprintf(output, " ");
				printf(" ");
			}
		}
		printf("\n");
		fclose(output);
	}
}