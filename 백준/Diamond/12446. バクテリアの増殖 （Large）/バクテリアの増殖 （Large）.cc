<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

int memo[1001];
int phi[1001];


int power_modular (int X, int Y, int M);
int bacteria_modular (int A, int B, int C);

int main() {
    for(int i = 0; i < 1001;i++) phi[i] = i;
    for(int i = 2; i < 1001;i++) {
        if(phi[i] == i) {
            for(int j = i; j < 1001;j+=i) {
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }
	int T;
	scanf("%d", &T);
	int A, B, C;
	for (int i = 1; i <= T; i++) {
		memset(memo, 0, sizeof(memo));
		scanf("%d %d %d", &A, &B, &C);
		printf("Case #%d: %d\n", i, bacteria_modular (A, B, C));
	}
	return 0;
}

int power_modular(int a, int b, int MMM) { 
    int ret = 1; 
    for (; b; b >>= 1, a = (a * a) % MMM)
        if (b & 1)ret = (ret * a) % MMM; 
    return ret; 
}

int bacteria_modular (int A, int B, int C) {
	if (B == 1) {
		return power_modular(A, A, C);
	}
	int temp = C;

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
            // printf("%d ",memo[temp]);
            temp = K;
		}
        // printf("\n");
		idx++;
	}
	return memo[C];
=======
#include <stdio.h>
#include <string.h>

int memo[1001];
int phi[1001];


int power_modular (int X, int Y, int M);
int bacteria_modular (int A, int B, int C);

int main() {
    for(int i = 0; i < 1001;i++) phi[i] = i;
    for(int i = 2; i < 1001;i++) {
        if(phi[i] == i) {
            for(int j = i; j < 1001;j+=i) {
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }
	int T;
	scanf("%d", &T);
	int A, B, C;
	for (int i = 1; i <= T; i++) {
		memset(memo, 0, sizeof(memo));
		scanf("%d %d %d", &A, &B, &C);
		printf("Case #%d: %d\n", i, bacteria_modular (A, B, C));
	}
	return 0;
}

int power_modular(int a, int b, int MMM) { 
    int ret = 1; 
    for (; b; b >>= 1, a = (a * a) % MMM)
        if (b & 1)ret = (ret * a) % MMM; 
    return ret; 
}

int bacteria_modular (int A, int B, int C) {
	if (B == 1) {
		return power_modular(A, A, C);
	}
	int temp = C;

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
            // printf("%d ",memo[temp]);
            temp = K;
		}
        // printf("\n");
		idx++;
	}
	return memo[C];
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}