#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char* first = argv[1];
	char txt[100] = { 0 };
	char* ABC = "0123456789!@#$%^&*()_+=-<>,./?'abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ";
	while (1) {
		printf("\nEnter a string: \n");
		int check = 0;
		int counter[81] = { 0 };
		for (int i = 0; i < strlen(first); i++) {
			for (int j = 0; j < strlen(ABC); j++) {
				if (first[i] == ABC[j])
					counter[j]++;
			}
		}
		gets(txt);
		if (txt[0] == '\0')
			break;
		for (int i = 0; i < strlen(txt); i++) {
			for (int j = 0; j < strlen(ABC); j++) {
				if (txt[i] == ABC[j]) {
					counter[j]--;
					if (counter[j] < 0) {
						check++;
						printf("false\n");
						break;
					}
				}
			}
			if (check > 0)
				break;
		}
		if (check == 0) {
			printf("true\n");
		}
	}
	return 0;
}