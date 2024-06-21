#include <iostream>
#include <vector>


using namespace std;


class Queue{
private:
    int arr[10001];
    int front;
    int back;
public:
    Queue(){   
        front = 0;
        back = -1;
    }
    bool empty(){
        if (front > back) return 1;
        else return 0;
    }
    void push(int item){
        arr[++back] = item;
    }
    int pop(){
        if (empty()){
            return -1;
        } else
        return arr[front++];
    }

    int size(){
        return back-front+1;
    }
    int getfront(){
        if (empty()){
            return -1;
        } else
        return arr[front];
    }
    int getback(){
        if (empty()){
            return -1;;
        } else
        return arr[back];
    }
};




int main(){ 

    int N;
    cin >> N;   
    Queue queue;

    for (int i = 0; i < N; ++i) {
        string prefix;
        int x = -1;
        cin >> prefix;
        if (prefix == "push") {
            cin >> x;
            queue.push(x);
        } else if (prefix == "pop"){
            cout << queue.pop() << "\n";
        } else if (prefix == "empty"){
            cout << queue.empty() << "\n"; 
        } else if (prefix == "size"){
            cout << queue.size() << "\n";
        } else if (prefix == "front"){
            cout << queue.getfront() << "\n";
        } else if (prefix == "back"){
            cout << queue.getback() << "\n";
        } 


    }
        
    return 0;
}



