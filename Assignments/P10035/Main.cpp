#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while(true) {
        string first, second;
        cin >> first;
        cin >> second;
        if(first == "0" && second == "0") {
            break;
        }

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        bool carrying = false;
        int carrys = 0;
        //there can't be a carry if one number doesn't even have a digit in that spot
        int digits = min(first.length(), second.length());
        for(int i = 0; i < digits; i++) {
            int a = first[i] - '0';
            int b = second[i] - '0';
            if((a + b + carrying) > 9) {
                carrys++;
                carrying = true;
            } else {
                carrying = false;
            }
        }
        //ok turns out the comment on line 21 is wrong
        //because if the next digit is a 9 and you carried 
        //then you can carry again without having anything from the other number
        if(digits < first.length()) {
            if(first[digits] == '9' && carrying) {
                int i = digits;
                while(first[i] == '9') {
                    i++;
                    carrys++;
                } 
            }
        }
        if(digits < second.length()) {
            if(second[digits] == '9' && carrying) {
                int i = digits;
                while(second[i] == '9') {
                    i++;
                    carrys++;
                } 
            }
        }
        if(carrys == 0) {
            cout << "No carry operation.\n";
        } else if(carrys == 1) {
            cout << "1 carry operation.\n";
        } else {
            cout << carrys << " carry operations.\n";
        }
        
    }
}