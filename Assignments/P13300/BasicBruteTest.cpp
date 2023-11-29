#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

float calculateArea(pair<int, int> t1, pair<int, int> t2, pair<int, int> t3) {
    return (abs(t1.first * (t2.second - t3.second) + t2.first * (t3.second - t1.second) + t3.first * (t1.second - t2.second)) * 10 >> 1) / 10.0;
}

int main() {
    int numTestCases;
    while(cin >> numTestCases) {
        vector<pair<int, int>> coordinates;
        for (int i = 0; i < numTestCases; ++i) {
            int x, y;
            cin >> x >> y;
            coordinates.push_back(make_pair(x, y));
        }
        
        float maxArea = -999;
        for(pair<int, int> t1 : coordinates) {
            for(pair<int, int> t2 : coordinates) {
                for(pair<int, int> t3 : coordinates) {
                    if(t1 == t2 || t1 == t3 || t2 == t3) {
                        continue;
                    } 
                    float area = calculateArea(t1, t2, t3);
                    if(area > maxArea)
                        maxArea = area;
                }
            }
        }
        cout << fixed << setprecision(1) << maxArea << endl;

    }
    return 0;
}