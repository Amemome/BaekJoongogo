#include <stdio.h>
#include <string.h>

int memo[1001];
int phi[1001];

int PHI (int X);

int power_modular (int X, int Y, int M);
int bacteria_modular (int A, int B, int C);

int main() {
	int T;
	scanf("%d", &T);
	int A, B, C;
	for (int i = 1; i <= T; i++) {
		memset(memo, 0, sizeof(memo));
		memset(phi, 0, sizeof(phi));
		scanf("%d %d %d", &A, &B, &C);
		printf("Case #%d: %d\n", i, bacteria_modular (A, B, C));
	}
	return 0;
}

int PHI (int X) {
	int answer = X;
	for (int i = 2; i * i <= X; i++) {
		if (X % i == 0) {
			while (X % i == 0) {
				X /= i;
			}
			answer -= answer / i;
		}
	}
	if (X > 1) {
		answer -= answer / X;
	}
	return answer;
}

int power_modular (int X, int Y, int M) {
	int answer = 1;
	while(Y) {
		if (Y & 1) {
			answer = answer * X % M;
		}
		X = X * X % M;
		Y >>= 1;
	}
	return answer;
}

int bacteria_modular (int A, int B, int C) {
	if (B == 1) {
		return power_modular(A, A, C);
	}
	int temp = C;
	while(temp > 1) {
		phi[temp] = PHI(temp);
		temp = PHI(temp);
	}
	temp = C;
	while(temp > 1) {
		memo[temp] = power_modular(A, A, temp);
		temp = phi[temp];
	}
	int idx = 1, K;
	while(idx < B) {
		temp = C;
		while(temp > 1) {
			K = phi[temp];
			memo[temp] = power_modular(memo[temp], memo[K] ? memo[K] : memo[K] + K, temp);
			temp = K;
		}
		idx++;
	}
	return memo[C];
}