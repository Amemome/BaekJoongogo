#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int top = -1;

int nums = 0;

int listnum = 0;

char list[200010];

void listappend(char ww) {
	list[listnum] = ww;
	listnum++;
}


void push(int stack[]) {
	top++;
	nums++;
	stack[top] = nums;
	
	listappend('+');

}

void pop(int stack[]) {
	top--;
	listappend('-');

}



int main() {

	int stack[100001];
	int N, fst, scd;
	scanf("%d", &N);

	scanf("%d", &fst);
	for (int i = 0; i < fst; ++i) {
		push(stack);
	}
	pop(stack);

	scd = fst;
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d", &fst);




		if (fst > scd) {


			while (fst != nums) {
				push(stack);
			}
			pop(stack);
		}
		else if (scd > fst) {
			if (fst != stack[top]) {
				printf("NO");
				return 0;
			}
			pop(stack);
		}
		scd = fst;
	}

	for (int i = 0; i < N * 2; i++) {
		printf("%c\n", list[i]);
	}
	return 0;

}









