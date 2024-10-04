#include <bits/stdc++.h>

using namespace std;

/*
브루트 포스 해봐일단.기약분수 <== 니까 어떤 한 수에서의 서로소를 다 구함.
다 구한 다음에 이걸 정렬하는거지 근데 이게 1/2 기준으로 대칭입니다. 1 -분수 하면 딱 대칭임.
그럼 그냥 반갈해도 ㄱㅊ은것.
그럼 서로소를 구하는 범위가 달라집니다. s의 서로소를 구하는데, s
*/

struct fac{
    int a,b;
    fac(int a,int b) : a(a) , b(b) {}   // a/b 의 형태
    fac() {a = 0; b = 0;}
};

bool Cmp(const fac& f1, const fac& f2) {
    return f1.a*f2.b < f1.b*f2.a;
}

vector<fac> seq = {fac(0,1)};

//서로소를 조금 더 최적화 해서 넣는 함수인데,, 에라토스테네스의 체 변형해서 쓸거임. 루트 m 해서 gcd 되는 것들을 다 처리할까?
void addprfac(int m) {
    vector<bool> prime(m/2+1,true);                                 // m 을 2로 나눈것 만큼만 구할거니까 +1 까지 해서 배열을 만들어 준다.
    prime[0] = false; 
    
    for(int i = 1; i  <= m/2; i++) { //gcd 가 1이 아닌것을 봅니다. gcd 가 1 이 아니면 12 2 3 이 나왔을 때, 걍 인수이면 트루나잖음. 이때 걍 박아버리는거.
        if(prime[i]) {
            if(__gcd(i,m) != 1) {
                for(int z = i; z <= m/2; z+=i) {
                    prime[z] = false;
                }
            } else {
                seq.push_back(fac(i,m));
            }
        }
    }
}

//5000 * 2500 번만 돌면 되는데.


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;

    /*
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= x/2; y++) {  
            if(__gcd(x,y) == 1) {
                seq.push_back(fac(y,x));
            }
        }
    }

    */

    for(int x = 1; x <= n; x++) {
            addprfac(x);
    }


    int siz = seq.size();

    for(int i = 0; i < siz; i++) {
        seq.push_back(fac(seq[i].b-seq[i].a,seq[i].b)); //그냥 1/2 두개 넣어버리죠? 나중에 처리함 ㅇ
    }

    if(k > siz) k++;
    
    nth_element(seq.begin(),seq.begin()+ k - 1,seq.end(),Cmp);
    fac result = seq[k-1];
    cout << result.a << ' ' << result.b ;

}