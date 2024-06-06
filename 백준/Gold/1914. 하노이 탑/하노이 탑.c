#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void verybigprint(double x) {
	char buffer[100];
	snprintf(buffer, sizeof(buffer), "%.0f", x);

	
	int len = strlen(buffer);
	buffer[len - 1] -= 1;

	printf("%s\n", buffer);

}
void hatower(int n, int from, int temp, int to);

int main() {
	int N;
	int count = 0;

	scanf("%d", &N);

	
	double power = pow(2.0, N);
	verybigprint(power);

	

	if (N<=20) hatower(N, 1, 2, 3);  
}
void hatower(int n, int from, int temp, int to) { 

	if (n == 1) {                                 
		printf("%d %d\n", from, to);  
	}															
	else {                    
		hatower(n - 1, from, to, temp); 

		printf("%d %d\n", from, to); 

		hatower(n - 1, temp, from, to); 
	}
}