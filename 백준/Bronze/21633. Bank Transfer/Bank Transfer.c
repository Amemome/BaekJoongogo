#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num;
	float commit;
	scanf("%d", &num);
	commit = 25 + num / 100.0;
	if (commit < 100) printf("100.00");
	else if (commit > 2000) printf("2000.00");
	else printf("%.2f", commit);
	return 0;
}


