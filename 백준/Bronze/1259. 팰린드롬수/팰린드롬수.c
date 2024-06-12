#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



main() {

	char st[7];
	int n = 1;
	
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;


		int rn = n;
		int count = 0;
		int yesorno = 0;

		while (n != 0) {
			n /= 10;
			count += 1;
		}
		
		sprintf(st, "%d", rn);




		for (int i = 0; i < (count / 2); ++i) {
			if (st[i] != st[count - i - 1]) {
				yesorno++;
				
			}
		}

		if (yesorno == 0) printf("yes\n");
		else printf("no\n");
	 }


}