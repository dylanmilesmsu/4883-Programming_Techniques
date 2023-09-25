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
    bool fock = false;
    for(int i = 0; i < trains; i++) {
        int input;
        cin >> input;
        enteringTrains.push_back(input);
    }
    bool end = false;
    while(!end) {
        depot = {};
        bool success = true;
        int input2;
        if(input2 == 0) {
            end = true;
            break;
        }
        int index = 0;
        for(int i = 0; i < trains; i++) {
            cin >> input2;
            if(input2 == enteringTrains[index]) {
                cout << "cin " << input2 << endl;
                index++;
                continue;
            } else {
                cout << "pushing " << input2 << " to stack" << endl;
                depot.push(input2);
            }
        }
        
        // cin >> input2;
        // for(int x : enteringTrains) {
        //     //this cant be enhanced loop
        //     //we should do enterTrains[x]
        //     cin >> input2;
        //     if(input2 == x) {
        //         cout << "cin " << input2 << endl;
        //         continue;
        //     } else {
        //         cout << "pushing " << input2 << " to stack\n";
        //         depot.push(input2);

        //     }
        // }
        if(index == trains) {
            cout << "yes" << endl;
            continue;
        } else {
            for(int i = index; i < trains; i++) {
                cout << depot.top() << " " << enteringTrains[i] << endl;
                if(enteringTrains[i] == depot.top()) {
                    depot.pop();
                    continue;
                } else {
                    cout << "no :(" << endl;
                    return 0;
                }
            }
            cout << "yes" << endl;
        }

        // for(int x = 0; x < depot.size(); x++) {
        //     if(depot.top() == input2) {
        //         depot.pop();
        //         cin >> input2;
        //         cout << "cin " << input2 << endl;
        //     } else {
        //         cout << depot.top() + " was in stack, looking for " << input2 << endl;
        //         success = false;
        //     }
        // }
        // if(success) {
        //     cout << "yes" << endl;
        // } else {
        //     cout << "no" << endl;
        // }
    }
}