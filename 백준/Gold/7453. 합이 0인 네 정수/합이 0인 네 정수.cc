<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_map>

#define ref(i,n) for(int i = 0; i < n; i++)
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a;
    vector<long long> b;
    vector<vector<long long>> ip(4,vector<long long>(4001,0));

    ref(i,n){
        cin >> ip[0][i] >> ip[1][i] >> ip[2][i] >> ip[3][i];
    }
    
    ref(x,n){
        ref(y,n){
            a.push_back(ip[0][x]+ip[1][y]);
            b.push_back(ip[2][x]+ip[3][y]);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    long long result = 0;

    long long left = 0, right = b.size()-1;
    while(left < b.size() && right >= 0){
        long long now = a[left] + b[right];
        if(now == 0) {
            long long x = 1, y = 1;
            for(long long nx = left+1; nx < a.size(); nx++) {
                if(a[nx] == a[left]) x++;
                else break;
            }

            for(long long ny = right-1; ny >= 0; ny--) {
                if(b[ny] == b[right]) y++;
                else break;
            }

            result += x*y;
            left += x;
            right -= y;
        }
        else if(now > 0) {
            right--;
        } else {
            left++;
        }

    }

    cout << result;
    
    return 0;
=======
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <unordered_map>

#define ref(i,n) for(int i = 0; i < n; i++)
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a;
    vector<long long> b;
    vector<vector<long long>> ip(4,vector<long long>(4001,0));

    ref(i,n){
        cin >> ip[0][i] >> ip[1][i] >> ip[2][i] >> ip[3][i];
    }
    
    ref(x,n){
        ref(y,n){
            a.push_back(ip[0][x]+ip[1][y]);
            b.push_back(ip[2][x]+ip[3][y]);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    long long result = 0;

    long long left = 0, right = b.size()-1;
    while(left < b.size() && right >= 0){
        long long now = a[left] + b[right];
        if(now == 0) {
            long long x = 1, y = 1;
            for(long long nx = left+1; nx < a.size(); nx++) {
                if(a[nx] == a[left]) x++;
                else break;
            }

            for(long long ny = right-1; ny >= 0; ny--) {
                if(b[ny] == b[right]) y++;
                else break;
            }

            result += x*y;
            left += x;
            right -= y;
        }
        else if(now > 0) {
            right--;
        } else {
            left++;
        }

    }

    cout << result;
    
    return 0;
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}