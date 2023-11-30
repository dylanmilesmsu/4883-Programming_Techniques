#include <iostream>
#include <string>
#include <vector>

using namespace std;

int img[99][99] = {2};

void markConnectedOnes(vector<vector<int>>& grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Check if the current position is within bounds and is a 1
    if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1) {
        // Mark the current position as visited (set to 0)
        grid[row][col] = 0;

        // Recursively mark connected ones in all directions
        markConnectedOnes(grid, row + 1, col); // Down
        markConnectedOnes(grid, row - 1, col); // Up
        markConnectedOnes(grid, row, col + 1); // Right
        markConnectedOnes(grid, row, col - 1); // Left

        markConnectedOnes(grid, row + 1, col + 1); // Diagonal down-right
        markConnectedOnes(grid, row - 1, col + 1); // Diagonal up-right
        markConnectedOnes(grid, row + 1, col - 1); // Diagonal down-left
        markConnectedOnes(grid, row - 1, col - 1); // Diagonal up-left
    }
}

int countAndMarkConnectedOnes(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int connectedOnesCount = 0;

    // Loop through each element in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If a 1 is found, mark connected ones and increment the counter
            if (grid[i][j] == 1) {
                markConnectedOnes(grid, i, j);
                connectedOnesCount++;
            }
        }
    }

    return connectedOnesCount;
}

//initially I used a 2d array
//but changed my mind and didn't wanna rewrite code
//so we're doing this :D                                    //lines    length

vector<vector<int>> convertToVector(const int img[][99], int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols, 0));


    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            result[y][x] = img[x][y];
        }
    }


    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         result[i][j] = img[i][j];
    //     }
    // }

    return result;
}

// int removeEagle(int _x, int _y) {
//     for(int x = _x-1; x < _x+1; x++) {
//         for(int y = _y-1; y < _y + 1; y++) {
//             if(x >= 0 && y >= 0) {
//                 if(img[x][y] == 1) {
//                     img[x][y] = 0;
//                     if(!(x == _x && y == _y)) {
//                         cout << "recur" << endl;
//                         removeEagle(x, y);
//                     }
//                 }
//             }
//         }
//     }
// }

void printImg(int lines, int length) {
    for(int y = 0; y < lines; y++) {
        for(int x = 0; x < length; x++) {
            cout << img[x][y];
        }
        cout << "\n";
    }
}

int main() {
    int iterations = 0;
    int lines;
    while(cin >> lines) {
        iterations++;
        int length = 0;
        char x[1024];
        cin.getline(x, 1024, '\n');

        for(int y = 0; y < lines; y++) {
            char s[1024];
            cin.getline(s, 1024, '\n');
            
            int x = 0;
            while(s[x] != NULL) {
                int intDigit = s[x] - '0';
                img[x][y] = intDigit;
                // cout << x << " " << y << endl; 
                x++;
            }
            length = x;
        }

        // printImg(lines, length);

        vector<vector<int>> grid = convertToVector(img, lines, length);
        // for (vector<int> row : grid) {
        //     for (int value : row) {
        //         cout << value << " ";
        //     }
        //     cout << endl;
        // }
        // Example usage with the previously provided functions
        int result = countAndMarkConnectedOnes(grid);

        cout << "Image number " << iterations << " contains " << result << " war eagles." << endl;

        // Display the updated grid
        // for (vector<int> row : grid) {
        //     for (int value : row) {
        //         cout << value << " ";
        //     }
        //     cout << endl;
        // }
    }   
}