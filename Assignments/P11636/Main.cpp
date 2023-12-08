#include <iostream>

using namespace std;

int main() {
    int goal;
    int i = 0;
    while (cin >> goal) {
        i++;
        if(goal < 0) {
            break;
        }
        int x = 1;
        int pastes = 0;
        while(x < goal) {
            x *= 2;
            pastes++;
        }
        cout << "Case " << i << ": " << pastes << endl;
    }
    
}