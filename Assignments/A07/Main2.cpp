//this is a version of it that i gave up on

#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    while(true) {
        int trains;
        cin >> trains;
        if(trains == 0) {
            break;
        }
        int i = 1;
        stack<int> depot; 
        while(true) {
            if(i > trains) {
                if(depot.size() > 0) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
                i = 1;
                depot = stack<int>();
            }
            int test;
            cin >> test;
            cout << test << endl;
            if(test == 0) {
                cout << endl;
                break;
            }
            if(test == i) {

            } else {
                if(depot.size() > 0 && depot.top() == i) {
                    depot.pop();
                } else {
                    depot.push(test);
                }
            }
            i++;
        }
    }
}