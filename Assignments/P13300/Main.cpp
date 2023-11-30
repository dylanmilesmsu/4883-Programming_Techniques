#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double calculateArea(pair<int, int> t1, pair<int, int> t2, pair<int, int> t3) {
    return ((t1.first * (t2.second - t3.second) + t2.first * (t3.second - t1.second) + t3.first * (t1.second - t2.second)));
}

int crossProduct(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
    int x1 = p2.first - p1.first;
    int y1 = p2.second - p1.second;
    int x2 = p3.first - p1.first;
    int y2 = p3.second - p1.second;
    return x1 * y2 - x2 * y1;
}

vector<pair<int, int>> findConvexHull(vector<pair<int, int>>& points) {
    int n = points.size();
    if (n < 3) {
        return points;
    }

    sort(points.begin(), points.end());

    vector<pair<int, int>> lower, upper;
    for (int i = 0; i < n; ++i) {
        while (lower.size() >= 2 && crossProduct(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) <= 0) {
            lower.pop_back();
        }
        lower.push_back(points[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        while (upper.size() >= 2 && crossProduct(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    vector<pair<int, int>> convexHull;
    for (int i = 0; i < lower.size(); ++i) {
        convexHull.push_back(lower[i]);
    }
    for (int i = 1; i < upper.size() - 1; ++i) {
        convexHull.push_back(upper[i]);
    }

    return convexHull;
}

int main() {
    int numTestCases;
    while (cin >> numTestCases) {
        vector<pair<int, int>> coordinates;
        for (int i = 0; i < numTestCases; ++i) {
            int x, y;
            cin >> x >> y;
            coordinates.push_back(make_pair(x, y));
        }

        vector<pair<int, int>> convexHull = findConvexHull(coordinates);

        double maxArea = -999;
        int n = convexHull.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double area = calculateArea(convexHull[i], convexHull[j], convexHull[k]);
                    maxArea = max(maxArea, area);
                }
            }
        }
        cout << fixed << setprecision(1) << maxArea << endl;
    }
    return 0;
}