#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        // cout << a << " " << b << endl;
        int closestOddToA = a;
        if(a % 2 == 0)
            closestOddToA++;
        // cout << closestOddToA << endl;
        int sum = 0;
        for(int x = closestOddToA; x <= b; x += 2) {
            if(x <= b) {
                // cout << x << endl;
                sum += x;
            }
        }
        cout << "Case " << i+1 << ": " << sum << "\n";
    }
}