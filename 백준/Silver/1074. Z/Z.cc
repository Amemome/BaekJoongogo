#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//피보나치 함수에서 끝에서 0과 1이 나오는 횟수를 출력.
//3 은 1 2 
//4 는 
//pair 로 잘 하면 될 거 같음. 
//0 1 0    1  0 1  2 
//x,y   x+1,y
//x,y+1 x+1,y+1
//counter 를 하나씩 올립시다.

int Z(int n,int x, int y,int &count){  //N 일떄  2^N
    
    int half = (1<<(n-1));
    int powhalf = half*half;

    int xpos = x/half;   // 0을 나누면 어떻게 되는가.
    int ypos = y/half;   //N이 주어졌을 때 가로세로의 크기는 2^N 임
    
    

    count += xpos*(powhalf) + 2*ypos*(powhalf);        
    


    if (n == 1){
        return count;
    }

    if (x>=(half)) {
        x -= half;
    }
    if (y>=half) {
        y -= half;
    }
    
    return Z(n-1 , x  , y , count);

}
int main(){ 

    int N,r,c;
    cin >> N>>r>>c;
    int count = 0;

    cout << Z(N,c,r,count);

    

    //r 과 c 에 있는걸 넣으면.
    

    
    
    return 0;
}



