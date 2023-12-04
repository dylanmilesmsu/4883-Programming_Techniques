#include <iostream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int people;
    bool first = true;
    while(cin >> people) {
        if(!first) {
            cout << "\n";
        }
        first = false;
        map<string,int> personmoneymap;
        vector<string> peoplenameordered;
        for(int i = 0; i < people; i++) {
            string name;
            cin >> name;
            personmoneymap[name] = 0;
            peoplenameordered.push_back(name);
        }
        for(int i = 0; i < people; i++) {
            string name;
            cin >> name;

            int money;
            cin >> money;
            int people;
            cin >> people;
            for(int x = 0; x < people; x++) {
                string othername;
                cin >> othername;
                personmoneymap[name] = personmoneymap[name] - money/people;
                personmoneymap[othername] = personmoneymap[othername] + money/people;
            }
        }
        for(string n : peoplenameordered) {
            cout << n << " " << personmoneymap[n] << "\n";
        }
    }
}