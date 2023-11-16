#include <iostream>

using namespace std;

int cycle(int i) {
    int cycles = 1;
    while(i > 1) {
        if(i % 2 == 1)
            i = 3*i + 1;
        else
            i = i >> 1;
        cycles++;
    }
    return cycles;
}

int main() {
    int i, j, o;
    int n;
    while(cin >> i) {
        cin >> j;
        cout << i << " " << j << " ";
        int ans = 0;
        for(n = min(i, j); n <= max(i, j); n++) {
            ans = max(cycle(n), ans);
        }
        cout << ans << "\n";

    }
}