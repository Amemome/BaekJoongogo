<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;


struct pos{
    double x,y;
    pos(double x, double y) :x(x) , y(y) {}
};

struct hiway{
    double on_way,uclid;
    hiway(double on_way, double uclid) : on_way(on_way) , uclid(uclid) {} //onway 는 고속도로 상 x 축의 위치. uclid 는 onway 에서 가지는 거리의 최댓값
};


double distance(double x1, double y1, double x2, double y2){
    return (x2*x2 + y2*y2 - x1*x1 - y1*y1)/(2*(x2-x1));
}

double euclid(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N,L;
    deque<pos> stack;
    deque<hiway> postack;

    cin>>N>>L;
    
    for(int i = 0; i < N; i++){
        double x,y;
        cin >> x >> y;
        y = abs(y);

        if(stack.empty()){
            stack.push_back(pos(x,y));
            continue;
        }

        double x1 = stack.back().x; 
        double y1 = stack.back().y;
        double position_on_rail = distance(x1,y1,x,y);

        if(x1==x){
            if(y1 <= y) {
                continue;
            } else {
                stack.pop_back();
                if(stack.empty()) {
                    stack.push_back(pos(x,y));
                    continue;
                }
                if(!postack.empty()){
                    postack.pop_back();
                }
                
            }
        }
        

        while(stack.size() > 1){
            x1 = stack.back().x; 
            y1 = stack.back().y;
            position_on_rail = distance(x1,y1,x,y);

            if(postack.back().on_way >= position_on_rail) { // 계산한 고속도로위 좌표가 스택에 있는 고속도로 위 좌표보다 앞에 있으면?
                stack.pop_back();
                postack.pop_back();
            } else {
                break;
            }
        }
        x1 = stack.back().x; 
        y1 = stack.back().y;
        position_on_rail = distance(x1,y1,x,y);


        stack.push_back(pos(x,y));
        postack.push_back(hiway(position_on_rail,euclid(position_on_rail,0,x,y))); 
        
    }

    while(stack.size() > 1 && postack.front().on_way < 0) {
        stack.pop_front();
        postack.pop_front();
    }
    while(stack.size() > 1 && postack.back().on_way > L) {
        stack.pop_back();
        postack.pop_back();
    }




    if(stack.size() == 1) { //만약에 하나밖에 없으면 양 끝에 대해서 검사를 한 후에 출력.
        double mini= max(euclid(0,0,stack.front().x,stack.front().y),euclid(stack.back().x,stack.back().y,L,0));
        cout<< fixed << setprecision(6) << mini;
        return 0;
    }

    double maxnum = 0;

    for(auto D : postack){ //점이 2개 이상이면 postack 에 뭔가 있어야함.
        maxnum = max(maxnum, D.uclid);
    }

    maxnum = max({maxnum,euclid(0,0,stack.front().x,stack.front().y),euclid(stack.back().x,stack.back().y,L,0)});

    cout<< fixed << setprecision(6) << maxnum;

    return 0;
    //마지막에 최후의 값과 비교하기
}
=======
#include <bits/stdc++.h>

using namespace std;


struct pos{
    double x,y;
    pos(double x, double y) :x(x) , y(y) {}
};

struct hiway{
    double on_way,uclid;
    hiway(double on_way, double uclid) : on_way(on_way) , uclid(uclid) {} //onway 는 고속도로 상 x 축의 위치. uclid 는 onway 에서 가지는 거리의 최댓값
};


double distance(double x1, double y1, double x2, double y2){
    return (x2*x2 + y2*y2 - x1*x1 - y1*y1)/(2*(x2-x1));
}

double euclid(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    int N,L;
    deque<pos> stack;
    deque<hiway> postack;

    cin>>N>>L;
    
    for(int i = 0; i < N; i++){
        double x,y;
        cin >> x >> y;
        y = abs(y);

        if(stack.empty()){
            stack.push_back(pos(x,y));
            continue;
        }

        double x1 = stack.back().x; 
        double y1 = stack.back().y;
        double position_on_rail = distance(x1,y1,x,y);

        if(x1==x){
            if(y1 <= y) {
                continue;
            } else {
                stack.pop_back();
                if(stack.empty()) {
                    stack.push_back(pos(x,y));
                    continue;
                }
                if(!postack.empty()){
                    postack.pop_back();
                }
                
            }
        }
        

        while(stack.size() > 1){
            x1 = stack.back().x; 
            y1 = stack.back().y;
            position_on_rail = distance(x1,y1,x,y);

            if(postack.back().on_way >= position_on_rail) { // 계산한 고속도로위 좌표가 스택에 있는 고속도로 위 좌표보다 앞에 있으면?
                stack.pop_back();
                postack.pop_back();
            } else {
                break;
            }
        }
        x1 = stack.back().x; 
        y1 = stack.back().y;
        position_on_rail = distance(x1,y1,x,y);


        stack.push_back(pos(x,y));
        postack.push_back(hiway(position_on_rail,euclid(position_on_rail,0,x,y))); 
        
    }

    while(stack.size() > 1 && postack.front().on_way < 0) {
        stack.pop_front();
        postack.pop_front();
    }
    while(stack.size() > 1 && postack.back().on_way > L) {
        stack.pop_back();
        postack.pop_back();
    }




    if(stack.size() == 1) { //만약에 하나밖에 없으면 양 끝에 대해서 검사를 한 후에 출력.
        double mini= max(euclid(0,0,stack.front().x,stack.front().y),euclid(stack.back().x,stack.back().y,L,0));
        cout<< fixed << setprecision(6) << mini;
        return 0;
    }

    double maxnum = 0;

    for(auto D : postack){ //점이 2개 이상이면 postack 에 뭔가 있어야함.
        maxnum = max(maxnum, D.uclid);
    }

    maxnum = max({maxnum,euclid(0,0,stack.front().x,stack.front().y),euclid(stack.back().x,stack.back().y,L,0)});

    cout<< fixed << setprecision(6) << maxnum;

    return 0;
    //마지막에 최후의 값과 비교하기
}
>>>>>>> 83927147140e6241eb3207801e1b45ba28dcc889
