#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int iterations;
    cin >> iterations;

    cin.ignore(2, '\n');
    cin.ignore(1, '\n');

    vector<string> treeList;

    int newlines = 0;
    int i = 0;
    while(newlines < iterations) {
        string line;
        getline(cin, line);
        if(line.length() < 1) {
            sort(treeList.begin(), treeList.end());
            string temp;
            int num = 1;
            for(string s : treeList) {
                if(s != temp && temp.length() > 0) {
                    cout << temp << " " << fixed << setprecision(4) << (num / (treeList.size() + 0.0) * 100.0) << endl;
                    num = 1;
                }
                if(s == temp) {
                    num++;
                }
                temp = s;
            }
            cout << temp << " " << fixed << setprecision(4) << (num / (treeList.size() + 0.0) * 100.0) << endl;

            newlines++;
            treeList.clear();
            if(newlines != iterations)
                cout << endl;
        } else {
            treeList.push_back(line);
        }
        i++;
    }
}
