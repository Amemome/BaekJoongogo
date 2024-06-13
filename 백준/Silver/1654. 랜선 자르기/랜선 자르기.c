#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main() {
	int a, b; 
	int line[10001];
	scanf("%d %d", &a, &b);

	int MAX = 0;

	for (int i = 0; i < a; i++) {
		scanf("%d", &line[i]);
		if (line[i] > MAX) MAX = line[i];
	}
	
	long long start = 1;
	long long end = MAX;
	int result = 0;


	while (start <= end) {
		
		long long middle = (start + end) / 2;
		int sum = 0;

		for (int i = 0; i < a; i++) {
			sum += (line[i] / middle);
		}

		if (sum < b) {
			end = middle - 1;
		}
		else if (sum >= b) {
			start = middle + 1;
		}
	}

	printf("%lld", end);
	return 0;
}


