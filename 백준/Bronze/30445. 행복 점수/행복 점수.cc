<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
/*
길이가 N 인 수열이 주어진다.이때, 다음 쿼리를 수행하
q 1 Ai 를 v 로 바꿈.
q 2 i j  Ai ~ Aj 까지에서 크기가 가장 작은 값을 출력. 수열의 인덱스는 1 부터!
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin,s);


    int hap = 0;
    int sad = 0;

    for(auto x : s) {
        for(auto h : "HAPY") {
            if(h == x){
                hap+=1;
            }
        }

        for(auto d : "SAD") {
            if(d == x) {
                sad+=1;
            }
        }
    }

    long long result = 0;

    if(hap == 0 && sad == 0) {
        result = 50000;
        cout << result/1000 << ".00";
        return 0;
    }

    result =  hap * 100000 / (hap + sad);
    if(result % 10 >= 5) result += 10;

    result /= 10;
    
    double realresult = result / (double) 100;

    cout << fixed;
    cout.precision(2);

    cout << realresult;

    

    

=======
#include <bits/stdc++.h>

using namespace std;
/*
길이가 N 인 수열이 주어진다.이때, 다음 쿼리를 수행하
q 1 Ai 를 v 로 바꿈.
q 2 i j  Ai ~ Aj 까지에서 크기가 가장 작은 값을 출력. 수열의 인덱스는 1 부터!
*/

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin,s);


    int hap = 0;
    int sad = 0;

    for(auto x : s) {
        for(auto h : "HAPY") {
            if(h == x){
                hap+=1;
            }
        }

        for(auto d : "SAD") {
            if(d == x) {
                sad+=1;
            }
        }
    }

    long long result = 0;

    if(hap == 0 && sad == 0) {
        result = 50000;
        cout << result/1000 << ".00";
        return 0;
    }

    result =  hap * 100000 / (hap + sad);
    if(result % 10 >= 5) result += 10;

    result /= 10;
    
    double realresult = result / (double) 100;

    cout << fixed;
    cout.precision(2);

    cout << realresult;

    

    

>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
}