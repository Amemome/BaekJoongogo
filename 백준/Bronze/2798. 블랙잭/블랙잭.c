#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

	int n,m;
	
	scanf("%d %d", &n, &m);

	int result = 0;

	int arr[1000] = { 0 };

	for (int i = 0; i < n; ++i) {
		int sc;
		scanf("%d", &sc);
		arr[i] = sc;
	}

	for (int a = 0; a < n; ++a) {

		for (int b = 0; b < n; ++b) {

			for (int c = 0; c < n; ++c) {

				if ((a == b) || (b == c) || (c == a)) continue;

				int sum = 0;
				sum = arr[a] + arr[b] + arr[c];


				if (sum > m) continue;

				if (result <= sum) {
					result = sum;
				}

			}
		}



		


	}
	printf("%d", result);
	return 0;
}