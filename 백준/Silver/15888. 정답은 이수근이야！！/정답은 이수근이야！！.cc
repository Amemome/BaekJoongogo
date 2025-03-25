#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c; cin>>a>>b>>c;
    // if(a==0) {
    //     double tmp = (double) -c / b;
    //     if(tmp==2 or tmp==4 or tmp==8 or tmp==16 or tmp==32 or tmp==64) cout << "이수근";
    //     else cout << "둘다틀렸근";
    //     return 0
    // }
    double IS = (b*b-4*a*c);
    if(IS<=0) { //허근
        cout << "둘다틀렸근";
        return 0;
    }
    double v1 = (-b + sqrt(IS))/(2*a);
    double v2 = (-b - sqrt(IS))/(2*a);
    int bct = 0;
    if(v1==2 or v1==4 or v1==8 or v1==16 or v1==32 or v1==64) bct++;
    if(v2==2 or v2==4 or v2==8 or v2==16 or v2==32 or v2==64) bct++;

    if(bct == 2) {
        cout << "이수근";
    }


    
    else if(v1 - int(v1) == 0 and v2 - int(v2) == 0) cout << "정수근";

    else cout << "둘다틀렸근";



}