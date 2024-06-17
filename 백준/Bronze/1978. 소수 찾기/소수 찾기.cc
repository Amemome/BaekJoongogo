#include <stdio.h>

int isprime(int x){
    int i;
    for (i = 2; i < x; i++){
        if (x%i == 0) return 0;
    }
    return 1;
}

int main(){
    
    int a;
    scanf("%d",&a);
    int i;
    int count = 0;
    for (i=0;i<a;i++){
        int n;
        scanf("%d",&n);
        if(n==1) continue;
        if(isprime(n)==1) count++;
    }
    printf("%d",count);
}