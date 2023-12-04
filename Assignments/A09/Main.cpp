#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int lines;
    while(cin >> lines) {
        if(lines == 0)
            continue;
        int columnSums[100] = {0}, rowSums[100] = {0};
        for(int y = 0; y < lines; y++) {
            for(int x = 0; x < lines; x++) {
                int number;
                cin >> number;
                // cout << number << " x: " << x << " y: " << y << endl;
                columnSums[y] = columnSums[y] + number;
                rowSums[x] = rowSums[x] + number;
            }
        }
        int badColumns = 0;
        int badRows = 0;
        int oneBadColumn = 0;
        int oneBadRow = 0;
        for(int i = 0; i < lines; i++) {
            if(columnSums[i] % 2 != 0) {
                badColumns++;
                oneBadColumn = i;
                //saves the position in the chart of the bad number
                //if theres only one bad row and column then it should be accurate
            }
            if(rowSums[i] % 2 != 0) {
                badRows++;
                oneBadRow = i;
            }
        }
        if(badRows == 1 && badColumns == 1)
            cout << "Change bit (" << oneBadColumn + 1 << "," << oneBadRow + 1 << ")\n";
        else if(badRows == 0 && badColumns == 0)
            cout << "OK\n";
        else 
            cout << "Corrupt\n";
    }
}