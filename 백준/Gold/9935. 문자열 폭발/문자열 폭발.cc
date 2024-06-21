#include <iostream>
#include <vector>
#include <string>

using namespace std;

//일단 문자열을 벡터에 저장함. 그리고 폭탄 문자열은 boom 에 따로 저장함.
//폭탄 문자열의 size 에 따라서 달라지니까 따로 변수 빼놓음. 만약에 폭탄 문자열 길이가 4개면 인덱스를 3부터 시작해도 될듯.'
//012345678912 index.                                               
//mirkovniz     strlength - boomlength < index
//12ab  boom length 4

//46퍼에서 시간초과 걸리는데 아마도 erase 함수 때문인 것으로 추정. erase 함수를 없애기 위해서 stack 으로 갈아타자

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 

    string str;
    string boom;

    cin >> str >> boom;
    int boomlength = boom.length();

    vector<char> result;

 

    for(auto c:str){
        result.push_back(c); //문제 X

        if (result.size() >= boomlength){ //문제 X
            bool boomcehck = true;       // 뒤의 index 부터..
            for(int i = 0 ; i<boomlength;i++){ //해당 index 에서 boom의 길이 만큼 반복하며 폭탄문자열인지 확인
                int index = result.size() -1;
                if (result[index-i] != boom[boomlength-1-i]){  //하나라도 맞으면 index 를 증가시키고 break.
                    boomcehck = false;
                }
            }
            if(boomcehck){
                for(int i = 0; i<boomlength;i++){
                    result.pop_back();
                }
            }
    }


    }
        if(result.empty()){
        cout<<"FRULA";
    } else {
        for(auto c:result){
            cout<<c;
        }
        }
    return 0;


}
