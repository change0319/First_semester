#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int IntArray[] = { 1,10,100,1000 };
	char CharArray[] = { 'z','x','c','d' };
	printf("iArray: ");
	for (int i = 0; i < 4; ++i)
		printf("%d ", IntArray[i]);
	printf("\nCharArray: ");
	for (int i = 0; i < 4; ++i)
		printf("%c ", CharArray[i]);
	printf("\n");
	system("pause");
	return 0;
}