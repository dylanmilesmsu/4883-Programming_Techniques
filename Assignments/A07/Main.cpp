//good version that actually work :D

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int trains;
    //used a vector before but this is faster?
    int objective[1000]; //N ≤ 1000


    while(true) {
        cin >> trains;
        if(trains == 0)
            break;

        while(true) {
            //load first one in manually to check for 0
            cin >> objective[0];
            if(objective[0] == 0) { //new scenario
                cout << endl;
                break;
            }
            //load the rest of the trains
            //previously kept trying to solve this going int by int 
            //but loading them all in at once seems to be the way to go
            for(int i = 1; i < trains; i++) {
                cin >> objective[i]; // populate all the trains
            }

            stack<int> depot;
            int trainIn = 1;
            int werg = 0;
            while(trains >= trainIn) {
                //kept trying to solve this only pushing when needed
                //but yeah you just push all of them and insta pop if needed
                depot.push(trainIn); 

                while(!depot.empty() && objective[werg] == depot.top()) {
                    depot.pop();
                    werg++;
                    if(werg >= trains)
                        break;
                }
                trainIn++;
            }
            if(depot.empty()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}