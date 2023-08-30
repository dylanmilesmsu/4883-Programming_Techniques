#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    long B = 0, A = 0;
    
    while (cin >> A >> B) {
        
        cout << abs(B-A) << endl;
    }
    return 0;
}