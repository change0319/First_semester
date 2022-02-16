#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int str_len(const char* str) {
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
char* to_str(char* name) {
	char sym = '0';
	int count = 0;
	FILE* str;
	fopen_s(&str, name, "r");
	while (!feof(str)) {
		fscanf_s(str, "%c", &sym, 1);
		count++;
	}
	count--;
	char* arr = (char*)malloc(count * sizeof(char));
	fseek(str, 0, SEEK_SET);
	for (int i = 0; i < count; i++) {
		fscanf_s(str, "%c", &arr[i], 1);
	}
	arr[count] = '\0';
	fclose(str);
	return arr;
}
char* search(const char* str1, const char* str2) {
	int size = str_len(str2);
	const char* arr = str2;
	while (*str1 && *arr)
	{
		if (*str1++ == *arr)
			arr++;
		else
			arr = str2;
		if (!*arr)
		{
			const char* str2 = str1 - size;
			return str2;
		}
	}
	return NULL;
}
int search_count(const char* str1, const char* str2) {
	int counter = 0;
	const char* arr = str1;
	do {
		arr = search(arr, str2);
		++counter;
		if (arr == NULL)
			break;
		++arr;

	} while (arr != NULL);
	counter--;
	return counter;
}
void chartoarr() {
	printf("\n pain:(\n");
}
//void memory_clear(char* array) {
//	for (int i = 0;i < str_len(array);i++) {
//		free(array[i]);
//	}
//	free(array);
//}
void replace(char* substr, char* repl) {
	FILE* in, * out;
	fopen_s(&in, "input.txt", "r");
	fopen_s(&out, "output.txt", "w");
	int size = str_len(substr);
	while (!feof(in))
	{
		char c = fgetc(in);
		if (feof(in) != 0)
			break;
		if (c == substr[0])
		{
			int flag = 0;
			for (int j = 1; j < size; j++)
			{
				c = fgetc(in);
				if (c != substr[j])
				{
					fseek(in, (-j), SEEK_CUR);
					fprintf(out, "%c", substr[0]);
					flag += 1;
					break;
				}
			}
			if (flag == 0)
				fprintf(out, "%s", repl);
		}
		else
			fprintf(out, "%c", c);
	}
	fclose(in);
	fclose(out);
}
//char* replace(char* string, char* substr1, char* substr2) {
//	char* arr = (char*)malloc(str_len(string) * sizeof(char));
//	arr[str_len(string)] = '\n';
//	int size = str_len(substr1);
//	for (int i = 0;i < str_len(string);i++) {
//		if (string[i] == substr1[i]) {
//			int flag = 0;
//			for (int j = 1;j < size;j++) {
//				if (string[j] != substr1[j]) {
//					j -= j;
//					arr[j] = substr1[j];
//					flag += 1;
//					break;
//				}
//			}
//			if (flag == 0)
//				for (int i = 0, j = 0;i < str_len(string), j < str_len(substr2);i++, j++) {
//					arr[i] = substr2[j];
//				}
//		}
//		else {
//			arr[i] = string[i];
//		}
//	}
//}
void MainMenu() {
	system("cls");
	int count = 0;
	char* s1 = { "input.txt" };
	char* s2 = { "substring.txt" };
	char* s3 = { "substring2.txt" };
	char* string = to_str(s1);
	char* substring1 = to_str(s2);
	char* substring2 = to_str(s3);
	setlocale(LC_ALL, "Russian");
	printf("Выберите операцию:\n");
	printf("1)поиск подстроки в строке.\n");
	printf("2)подсчёт числа вхождений подстроки.\n");
	printf("3)разделение строки на массив строк по специальному символу.\n");
	printf("4)замена подстроки в строке другой подстрокой \n");
	while (!_kbhit());
	char numbers = _getch();
	system("cls");
	switch (numbers) {
		int checker = 0;
	case '1':
		if (search(string, substring1) != NULL) {
			printf("\nYes\n");
			/*memory_clear(string);
			memory_clear(substring1);
			memory_clear(substring2);*/printf("1)Выход в главное меню.\n2)Выход из программы.\n");
			scanf_s("%d", &checker);
			if (checker == 1) {
				MainMenu();
			}
			else
				exit(0);
		}
		else
			printf("No");
		break;
	case '2':
		count = search_count(string, substring1);
		/*memory_clear(string);
		memory_clear(substring1);
		memory_clear(substring2);*/
		printf("\n%d\n", count);
		printf("1)Выход в главное меню.\n2)Выход из программы.\n");
		scanf_s("%d", &checker);
		if (checker == 1) {
			MainMenu();
		}
		else
			exit(0);
		break;
	case '3':
		chartoarr();
		printf("1)Выход в главное меню.\n2)Выход из программы.\n");
		scanf_s("%d", &checker);
		if (checker == 1) {
			MainMenu();
		}
		else
			exit(0);
		break;
	case '4':
		replace(substring1, substring2);
		/*replace(string, substring1, substring2);*/
		/*memory_clear(string);
		memory_clear(substring1);
		memory_clear(substring2);*/
		printf("\nCheck output file ^_^\n");
		printf("1)Выход в главное меню.\n2)Выход из программы.\n");
		scanf_s("%d", &checker);
		if (checker == 1) {
			MainMenu();
		}
		else
			exit(0);
		break;
	default:
		printf("Неверно выбрана операция.");
		break;
	}
}
