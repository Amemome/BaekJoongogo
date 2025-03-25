<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

/*
staff@boanlab.com

*/
struct pos{
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
};



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    int left = 0,right = 0;

    int v;
    cin >> v;


    left += v;
    cin >> v;
    right += v;
    n -= 2;
    while(n--) {
        cin >>v;
        if(left <= right) {
            left += v;
        } else {
            right += v;
        }
    }

    int q = abs(left-right);

    int result = 0;

    while(q) {
        result += q/100;
        q %= 100;
        result += q/50;
        q %= 50;
        result += q/20;
        q %= 20;
        result += q/10;
        q %= 10;
        result += q/10;
        q %= 10;
        result += q/5;
        q %= 5;
        result += q/2;
        q %= 2;
        result += q/1;
        q %= 1;



    }
    
    
    cout << result;
    

    return 0;
=======
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

/*
staff@boanlab.com

*/
struct pos{
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
};



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    int left = 0,right = 0;

    int v;
    cin >> v;


    left += v;
    cin >> v;
    right += v;
    n -= 2;
    while(n--) {
        cin >>v;
        if(left <= right) {
            left += v;
        } else {
            right += v;
        }
    }

    int q = abs(left-right);

    int result = 0;

    while(q) {
        result += q/100;
        q %= 100;
        result += q/50;
        q %= 50;
        result += q/20;
        q %= 20;
        result += q/10;
        q %= 10;
        result += q/10;
        q %= 10;
        result += q/5;
        q %= 5;
        result += q/2;
        q %= 2;
        result += q/1;
        q %= 1;



    }
    
    
    cout << result;
    

    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}