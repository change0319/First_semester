#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int C = atoi(argv[3]);
	int x, y;
	FILE* in;
	fopen_s(&in, argv[4], "r");
	while (fscanf_s(in, "%d %d", &x, &y) != EOF) {
		if (A * x + B * y + C == 0)
			printf("%d %d: YES\n", x, y);
		else
		{
			printf("%d %d: NO\n", x, y);
		}
	}
	fclose(in);
	return 0;
}