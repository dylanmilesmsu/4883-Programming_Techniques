#include <iostream>
#include <string>

using namespace std;

int img[99][99] = {2};

int removeEagle(int _x, int _y) {
    for(int x = _x-1; x < _x+1; x++) {
        for(int y = _y-1; y < _y + 1; y++) {
            if(x >= 0 && y >= 0) {
                if(img[x][y] == 1) {
                    img[x][y] = 0;
                    if(!(x == _x && y == _y)) {
                        cout << "recur" << endl;
                        removeEagle(x, y);
                    }
                }
            }
        }
    }
}

int printImg(int lines, int length) {
    for(int y = 1; y < lines+1; y++) {
        for(int x = 0; x < length; x++) {
            cout << img[x][y];
        }
        cout << "\n";
    }
}

int main() {
    int lines;
    cin >> lines;
    int length = 0;
    for(int y = 0; y < lines+1; y++) {
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
    int warEagles = 0;
    bool recheck = false;
    do {
        printImg(lines, length);
        recheck = false;
        bool superbreak = false;
        for(int y = 1; y < lines+1; y++) {
            for(int x = 0; x < length; x++) {
                if(img[x][y] == 1) {
                    cout << "eagle found" << x << " " << y << endl;
                    warEagles++;
                    recheck = true;
                    removeEagle(x, y);
                    superbreak = true;
                    break;
                }
               
            }
            if(superbreak) {
                break;
            }
        }
    } while (recheck);

    cout << warEagles << endl;
    
}