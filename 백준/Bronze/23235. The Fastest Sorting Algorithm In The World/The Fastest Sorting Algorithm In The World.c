#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	char s;
	int count = 0;
	char buffer[2] = { 123, 123 };
	for (;;) {
		scanf("%1c", &s);
		buffer[0] = s;

		if ((buffer[0] == '0') && (buffer[1] == '\n')) break;

		buffer[1] = buffer[0];
		if (s == '\n')
			count++;
	

		

}
	for (int i =1; i<=count; ++i)
	printf("Case %d: Sorting... done!\n", i);
}








