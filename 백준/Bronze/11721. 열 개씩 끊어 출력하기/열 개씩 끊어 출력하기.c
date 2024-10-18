#include <stdio.h>
#include <string.h>



int main(void) {
    char s[101] = {};

    while(fgets(s,11,stdin) != NULL) {
        printf("%s\n",s);
    }

    return 0;
}