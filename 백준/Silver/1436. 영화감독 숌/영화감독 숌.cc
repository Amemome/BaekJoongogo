#include <iostream>
#include <string>

using namespace std;

int main(){ 

    int N;
    cin >> N;

    if (N == 1) {
        cout << 666;
        return 0;
    }

    int movie = 1666;

    while (N-1) {
        
        string str = to_string(movie);
        if (str.find("666") != string::npos) --N;
        movie++;
    }
    cout << movie-1;
    return 0;
}


