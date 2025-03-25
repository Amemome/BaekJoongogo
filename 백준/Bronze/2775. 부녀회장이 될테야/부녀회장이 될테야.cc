#include<iostream>

using namespace std;

int main() {
    
    int apt[15][15] = {0}; //층 , 호-1

    for(int i = 0;i <= 14; i++ ) {
        apt[0][i] = i+1;
    }
    
    for(int x = 1; x <= 14; x++) {
        for(int y = 0; y <= 14; y++) {
            
            for(int z = 0; z <= y ; z++ ) {
                apt[x][y] += apt[x-1][z] ;
            }
        }
    }
    
    
    int n ; cin >> n;
    for (int i = 0; i < n; i++) {
        int k,n;
        cin >> k;
        cin >> n;
        
        cout << apt[k][n-1] << '\n';
        
    }
    
    
    
    return 0;
} 