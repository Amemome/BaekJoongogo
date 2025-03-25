<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

/*
3000 * 2999 해서, 중점을 ++ 해버리기?
*/
int n;

struct pos {
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
    pos() {x = 0; y = 0;}

    bool operator<(const pos& other) const {
        if ( x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    vector<pos> star;
    map<pos,int> result;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        star.push_back(pos(x,y));
        result[pos(x+x,y+y)]++;
    }

    for(int X = 0; X < n; X++) {
        for(int Y = X+1; Y < n; Y++) {
            pos one = star[X];
            pos two = star[Y];
            result[pos(one.x+two.x,one.y+two.y)]+=2;
        }
    }

    int maxs = 0;

    for(auto& it : result) {
        maxs = max(maxs,it.second);

    }

    cout << maxs;

    
    
=======
#include <bits/stdc++.h>

using namespace std;

/*
3000 * 2999 해서, 중점을 ++ 해버리기?
*/
int n;

struct pos {
    int x,y;
    pos(int x,int y) : x(x) , y(y) {}
    pos() {x = 0; y = 0;}

    bool operator<(const pos& other) const {
        if ( x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    vector<pos> star;
    map<pos,int> result;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        star.push_back(pos(x,y));
        result[pos(x+x,y+y)]++;
    }

    for(int X = 0; X < n; X++) {
        for(int Y = X+1; Y < n; Y++) {
            pos one = star[X];
            pos two = star[Y];
            result[pos(one.x+two.x,one.y+two.y)]+=2;
        }
    }

    int maxs = 0;

    for(auto& it : result) {
        maxs = max(maxs,it.second);

    }

    cout << maxs;

    
    
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}