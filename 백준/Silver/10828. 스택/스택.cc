#include <iostream>
#include <vector>


using namespace std;


class Stack{
private:
    int arr[10001];
    int top;
public:
    Stack(){   
        top = -1;
    }
    void push(int item){
        arr[++top] = item;
    }
    int pop(){
        if (top == -1){
            return -1;
        } else
        return arr[top--];
    }
    bool empty(){
        if (top == -1) return 1;
        else return 0;
    }
    int size(){
        return top+1;
    }
    int gettop(){
        if (top == -1){
            return -1;
        } else
        return arr[top];
    }
};




int main(){ 

    int N;
    cin >> N;
    Stack stack;

    for (int i = 0; i < N; ++i) {
        string prefix;
        int x = -1;
        cin >> prefix;
        if (prefix == "push") {
            cin >> x;
            stack.push(x);
        } else if (prefix == "pop"){
            cout << stack.pop() << "\n";
        } else if (prefix == "empty"){
            cout << stack.empty() << "\n"; 
        } else if (prefix == "size"){
            cout << stack.size() << "\n";
        } else if (prefix == "top"){
            cout << stack.gettop() << "\n";
        } 


    }
        
    return 0;
}



