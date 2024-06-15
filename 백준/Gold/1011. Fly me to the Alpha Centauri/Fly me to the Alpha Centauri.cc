#include <iostream>
#include <string>

using namespace std;

int main(){ 

    int A;
    cin >> A;
    for(int i = 0; i < A; i++){
        int N,M;
        cin >> N >> M;

        int dist = M - N;

        int ns = 1;
        int count = 0;

        for (;;) {
            
            dist -= ns;
            count += 1;
            if (dist <= 0){
                break;
            }

            dist -= ns;
            count += 1;
            if (dist <= 0){
                break;
            }

            ns++;
        }

        cout << count << "\n";


    }
    return 0;
}


