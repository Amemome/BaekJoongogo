<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
유익한 문제 다시 풀어보기
*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int w,n; cin >> w >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(),arr.end());
	
	vector<int> check(800000); //탐색 점을 옮김. 왼쪽부터 훑으면서 순차적으로 옮기면 왼쪽에서 두개 뽑는 가능한 조합을 아무때나 만족시키면 되니
	int a,b,c,d;
	for(int idx = 1; idx < n-2; idx++) {

		for(int i = 0; i < idx; i++) {
			check[arr[idx] + arr[i]] = true;
		}
		for(int i = idx+2; i < n; i++) {
			if(arr[idx+1] + arr[i] >= w) {
				break;
			} else 
			if(check[w - (arr[idx+1] + arr[i])]) {
				cout << "YES";
				return 0;
			}
		}
		
	}
	cout << "NO";
	
	

}
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
유익한 문제 다시 풀어보기
*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int w,n; cin >> w >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(),arr.end());
	
	vector<int> check(800000); //탐색 점을 옮김. 왼쪽부터 훑으면서 순차적으로 옮기면 왼쪽에서 두개 뽑는 가능한 조합을 아무때나 만족시키면 되니
	int a,b,c,d;
	for(int idx = 1; idx < n-2; idx++) {

		for(int i = 0; i < idx; i++) {
			check[arr[idx] + arr[i]] = true;
		}
		for(int i = idx+2; i < n; i++) {
			if(arr[idx+1] + arr[i] >= w) {
				break;
			} else 
			if(check[w - (arr[idx+1] + arr[i])]) {
				cout << "YES";
				return 0;
			}
		}
		
	}
	cout << "NO";
	
	

}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
