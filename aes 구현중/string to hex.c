#include <stdio.h>


void main() {

	unsigned char msg[10000];


	unsigned char input[] = "hello00 ";

	unsigned int n = 0;

	scanf("%s", &msg);

	printf("%s\n", msg);


	n = sizeof(input) - 1;

	for (int j = 0; j < n; j++)
		printf("%02x ", input[j]);
	printf("\n");

	printf("msg byte block size is %d", n);

}