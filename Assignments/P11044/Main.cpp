#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        //another case of 
        cout << (a / 3) * (b / 3) << endl;
    }
}