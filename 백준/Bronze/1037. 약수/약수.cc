<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct pos{
    int x,y;
    pos(int x, int y) : x(x) , y(y) {}
};

long long result = 0;


/*

*/ 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n ; cin >> n;
    int max = 0;
    int min = 100000000;
    for(int i = 0; i < n; i++) {
        int c ; cin >> c;
        if(c > max) max = c;
        if(c < min) min = c;
    }

    cout << max * min;




    return 0;
=======
#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct pos{
    int x,y;
    pos(int x, int y) : x(x) , y(y) {}
};

long long result = 0;


/*

*/ 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n ; cin >> n;
    int max = 0;
    int min = 100000000;
    for(int i = 0; i < n; i++) {
        int c ; cin >> c;
        if(c > max) max = c;
        if(c < min) min = c;
    }

    cout << max * min;




    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}