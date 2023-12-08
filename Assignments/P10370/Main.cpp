#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int students;
        cin >> students;
        vector<int> grades;
        double average = 0;
        for(int x = 0; x < students; x++) {
            int grade;
            cin >> grade;
            grades.push_back(grade);
            average += grade;
        }
        average /= students + 0.0;
        int aboveAverageStudents = 0;
        for(int s : grades) {
            if(s > average) {
                aboveAverageStudents++;
            }
        }
        // cout << aboveAverageStudents << " " << students << endl;
        double amountOfAboveAverageStudents = aboveAverageStudents / (students + 0.0);
        cout << fixed << setprecision(3) << amountOfAboveAverageStudents*100 << "%\n";
    }
}