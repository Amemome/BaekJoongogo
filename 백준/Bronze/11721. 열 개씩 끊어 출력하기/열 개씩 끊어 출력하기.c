#include <stdio.h>
#include <string.h>



int main(void) {
    char s[101] = {};

    fgets(s,sizeof(s),stdin);

    for(int i = 0; s[i] != '\0'; i++) {
        if(i % 10 == 0 && i != 0) printf("\n");
        printf("%c",s[i]);
    }

    return 0;
}