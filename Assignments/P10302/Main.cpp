#include <iostream>

using namespace std;

int main() {
    unsigned long long int werg;
    while(cin >> werg) {
        unsigned long long int sum = 0;
        for(unsigned long long int i = 1; i <= werg; i++)
            sum += i*i*i;
        cout << sum << endl;
    }
}