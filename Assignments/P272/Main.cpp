#include <iostream>
#include <string>

using namespace std;
//to fix edge case """
                 //"""
bool insideQuotes = false;
//if that bool was inside the replacequotes function
//we'd get issues with some test cases.
string replaceQuotes(const string &input) {
    string result;

    for (char c : input) {
        if (c == '"') {
            insideQuotes = !insideQuotes;
            if (insideQuotes) {
                result += "``";
            } else {
                result += "''";
            }
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    string input;
    
    // Read input from cin
    while (getline(cin, input)) {

        // Replace quotes and print the result
        string output = replaceQuotes(input);
        cout << output << endl;
    }
    return 0;
}