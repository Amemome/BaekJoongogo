#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main() {
	int N, M;
	float sum;
	scanf("%d %d", &N, &M);
	
	sum = (N * M) / 24200.0;

	printf("%d", (int) ceil(sum));


	return 0;
}


