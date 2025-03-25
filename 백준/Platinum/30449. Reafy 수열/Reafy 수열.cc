#include <bits/stdc++.h>

using namespace std;

int mu[5001];

void initmu() {
    mu[1] = 1;
    for(int x = 1; x < 5001; x++) {
        for(int y = 2 * x; y < 5001; y+=x) {
            mu[y] -= mu[x]; //x에대해영향력뿌리기
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    initmu();

    int n,k;
    cin >> n >> k;

    double s = 0, e = 1;

    double m = 0;
    int c = 45;

    while(c--) {
        m = (s+e)/2;
        long long cnt = 0;
        vector<int> fracs(n+1); //n까지만큼만 볼거니까
        for(int i = 1; i <= n; i++) {
            fracs[i] = fracs[i-1] + (int) floor(m*i); //각 fracs 에다가 분모 n인 분수의 누적합저장. 어차피 누적합만 보니까.
        }
        //m 보다 왼쪽에 있는 항들의 카운트는. 포함배제원리를 이용하여 처리.
        //gcd(i,j)=d 가 있을 때, i=d*i' j=d*j'이라 하면 i',j' <= N/d이기때문에
        for(int i = 1; i <= n; i++) {
            cnt += fracs[floor(n/i)] * mu[i]; //뫼비우스 함수로 포배원 처리.
        }
        //k 번째 항은, k보다 작은 항이 k-1 개 있어야 하므로.
        if(cnt + 1 >= k) { //이분탐색을 수행한다. 이분탐색을 수행하므로 (1/2)^n 의 배수인 정확도를 갖는 값이 나올거임. 그래서 이거를 거의 무시할정도로 하려면 어떻게 해야할까? 소수 정밀도 미치는 범위까지 반복을 한다 
            e = m;
        } else if (cnt + 1 < k) {
            s = m;
        }
        
    }

    //소수를 어떻게 분수로 만듦? ㄹㅇ

    for(int i = 1 ; i <= n; i++) {
        if(fabs((i*m)-(round(i*m))) < 0.000000001) {
            cout << round(i*m) << ' ' << i;
            return 0;
        }
    }



    return 0;
}