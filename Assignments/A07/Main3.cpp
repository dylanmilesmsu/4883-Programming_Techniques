//this is a version of it that i gave up on

#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> depot;
    vector<int> enteringTrains;
    int trains;
    cin >> trains;
    for(int i = 0; i < trains; i++) {
        int input;
        cin >> input;
        enteringTrains.push_back(input);
    }
    bool reset = false;
    bool end = false;
    while(!end) {
        depot = {};
        bool success = true;
        int input2;
        if(reset) {
            cout << "resetting" << endl;
            depot = stack<int>();
            enteringTrains.clear();
            cin >> trains;
            cout << trains;
            if(trains == 0) {
                cout << "next line was still 0, ending" << endl;
                end = true;
                break;
            }
            for(int i = 0; i < trains; i++) {
                int input;
                cin >> input;
                enteringTrains.push_back(input);
            }
            reset = false;
        }
        // if(input2 == 0) {
        //     end = true;
        //     // break;
        // }
        int index = 0;
        for(int i = 0; i < trains; i++) {
            cin >> input2;
            if(input2 == 0) {
                cout << "reset hit" << endl;
                reset = true;
                break;
            }
            if(input2 == enteringTrains[index]) {
                index++;
                continue;
            } else {
                depot.push(input2);
            }
        }
        if(reset) {
            cout << "reset continue hit" << endl;
            continue;
            // break;
        }
        if(index == trains) {
            cout << "yes" << endl;
            continue;
        } else {
            for(int i = index; i < trains; i++) {
                if(enteringTrains[i] == depot.top()) {
                    depot.pop();
                    continue;
                } else {
                    cout << "no" << endl;
                    return 0;
                }
            }
            cout << "yes" << endl;
        }
    }
}