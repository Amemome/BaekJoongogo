#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {


    char whitetable[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
    };
    char blacktable[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
    };


	int n,m;

    int result = 100000;

    
	
	scanf("%d %d", &n, &m);
    getchar();

    char arr[100][100] = { 0 };

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            int sc;
            scanf("%c", &sc);
            arr[a][b] = sc;
        }
        getchar();
       
    }

	n -= 7;
	m -= 7;



    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {

            int counterblack = 0;
            int counterwhite = 0;
            int realcounter = 0;

            for (int x = 0; x < 8; ++x) {
                for (int y = 0; y < 8; ++y) {

                    char ar = arr[x+a][y+b];

                    if (ar != blacktable[x][y]) {
                        counterblack++;
                    
                    }

                    if (ar != whitetable[x][y]) {
                        counterwhite++;
                    }

                }

        
            }
            

            if (counterwhite >= counterblack) {
                realcounter = counterblack;
            }
            else {
                realcounter = counterwhite;
            }


            if (result > realcounter) {
                result = realcounter;
            }

 






            
        }
    }


    printf("%d", result);

    return 0;


}