#include <bits/stdc++.h>
using namespace std;

using ld = long long;
const int N = 100010;
ld n, k;
ld a[N];

char find() {
    for (ld i=1; i<=n; i++)
        if (a[i]==k*i)
            return 'T';
    for (ld i=1; i<n; i++)
        if (a[i]>=k*i && a[i+1]<=k*(i+1))
            return 'T';
    return 'F';
}

int main() {
    cin >> n;
    a[0] = 0;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> k;
    cout << find();
}