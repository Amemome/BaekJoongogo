#include <iostream>
#include <vector>


using namespace std;
//일단 괄호 -> 곱셈 나눗셈 -> 덧셈 이렇게 가야됨 
//문자열을 받아서 어떻게 할 것인가
// 괄호가 제일 문제임.

int main(){ 
    string pap;
    cin >> pap;

    int length = pap.length(); //길이저장

    if (pap[0] == 'A') {
        cout << "NP";
        return 0;
    } else if (pap == "P") {
        cout << "PPAP";
        return 0;
    } else if ((length-1)%3 != 0) {
        cout << "NP";
        return 0;
    }

    int now = 1;
    char left = pap[1],right = pap[2];
    int count = 0;


    while (1) {        //now 를 인덱스로 사용, 그렇기 때문에 길이에서 -1을 해줌.
        if (count < 0) {
            cout << "NP";
            return 0;
        } else if (now > length - 1){
            break;
        }

        if (left == 'A') {
            if (right == 'P') {  //AP
                  count--;
                  now += 2;
                  left = pap[now];
                  right = pap[now+1];
            } else{  //AA
                cout << "NP";
                return 0;
            }
        } else{
            count++;
            now +=1;
            left = right;
            right = pap[now+1];
        }
    }

    if (count == 0) {
        cout << "PPAP";
    } else {
        cout << "NP";
    }
        
    return 0;
}



