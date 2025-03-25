#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template <typename T>
int ccw(T x1,T y1,T x2,T y2,T x3,T y3) {
    ll CP = (ll) (x2-x1)*(y3-y1)- (ll) (y2-y1)*(x3-x1); //오버플로우 조심.
    return (CP>0) - (CP<0);
} //ccw=1 cw=-1 line=0

template <typename T>
bool segmentIntersect(T x1,T y1,T x2,T y2,T x3,T y3,T x4,T y4) {
    int c1 = ccw(x1,y1,x2,y2,x3,y3);
    int c2 = ccw(x1,y1,x2,y2,x4,y4);
    int c3 = ccw(x3,y3,x4,y4,x1,y1);
    int c4 = ccw(x3,y3,x4,y4,x2,y2);
    if(c1*c2>0||c3*c4>0) return 0;
    else if(c1||c2||c3||c4) return 1;
    else if(min(x1, x2) > max(x3, x4) || min(y1, y2) > max(y3, y4) || 
    min(x3, x4) > max(x1, x2) || min(y3, y4) > max(y1, y2))return 0;
    return 1;
} //false : 0 - true : 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    cout << segmentIntersect(x1,y1,x2,y2,x3,y3,x4,y4);
}
