#include <stdio.h>


int main() {
    
    int arr[10][10] = {};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
    printf("%d %d", (*(arr+1)+4), *(*(arr)+99) );

    return 0;
}