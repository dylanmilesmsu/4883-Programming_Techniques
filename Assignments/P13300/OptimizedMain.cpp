#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double calculateArea(const pair<int, int>& t1, const pair<int, int>& t2, const pair<int, int>& t3) {
    return (abs(t1.first * (t2.second - t3.second) + t2.first * (t3.second - t1.second) + t3.first * (t1.second - t2.second)) * 10 >> 1) / 10.0;
}

// Calculate the cross product of vectors p1p2 and p1p3
int crossProduct(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
    int x1 = p2.first - p1.first;
    int y1 = p2.second - p1.second;
    int x2 = p3.first - p1.first;
    int y2 = p3.second - p1.second;
    return x1 * y2 - x2 * y1;
}

// Calculate the square of the Euclidean distance between two points
int squaredDistance(const pair<int, int>& p1, const pair<int, int>& p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

// Compare function to sort points based on polar angles
bool compare(const pair<int, int>& referencePoint, const pair<int, int>& p1, const pair<int, int>& p2) {
    int cp = crossProduct(referencePoint, p1, p2);
    if (cp == 0) {
        // If two points have the same angle, sort by distance from the reference point
        return squaredDistance(referencePoint, p1) < squaredDistance(referencePoint, p2);
    }
    return cp > 0;
}

vector<pair<int, int>> findConvexHull(vector<pair<int, int>>& points, const pair<int, int>& referencePoint) {
    int n = points.size();

    // Handle the case when there are less than 3 points
    if (n < 3) {
        return points;
    }

    // Sort the points based on polar angles
    sort(points.begin(), points.end(), [referencePoint](const pair<int, int>& p1, const pair<int, int>& p2) {
        return compare(referencePoint, p1, p2);
    });

    // Initialize the convex hull with the first two sorted points
    deque<pair<int, int>> convexHull;
    convexHull.push_back(points[0]);
    convexHull.push_back(points[1]);

    // Construct the convex hull
    for (int i = 2; i < n; ++i) {
        while (convexHull.size() > 1 && crossProduct(convexHull[convexHull.size() - 2], convexHull.back(), points[i]) <= 0) {
            convexHull.pop_back();
        }
        convexHull.push_back(points[i]);
    }

    return vector<pair<int, int>>(convexHull.begin(), convexHull.end());
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
        
        double maxArea = -999;
        for (size_t i = 0; i < coordinates.size(); ++i) {
            for (size_t j = i + 1; j < coordinates.size(); ++j) {
                for (size_t k = j + 1; k < coordinates.size(); ++k) {
                    double area = calculateArea(coordinates[i], coordinates[j], coordinates[k]);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }

        cout << fixed << setprecision(1) << maxArea << endl;
    }
    return 0;
}