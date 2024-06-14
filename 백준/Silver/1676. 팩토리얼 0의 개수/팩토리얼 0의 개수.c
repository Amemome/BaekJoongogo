#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>


int main() {


    int N;
    int result = 0;
    scanf("%d", &N);

    result += N / 5;
    result += N / 25;
    result += N / 125;

    printf("%d", result);

    return 0;
}

