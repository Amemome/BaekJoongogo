#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MXN 6500
/*

*/
void solve() {
	string s; cin >> s;
	int result = 0;
	int tmp = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'X') {
			tmp = 0;
		} else {
			tmp++;
		}
		if(tmp != 0) result += tmp;
	}
	cout << result << '\n';
}

int main() {
	int n; cin >> n;
	while(n--) solve();
	
	
}