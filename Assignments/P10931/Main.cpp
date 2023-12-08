#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        int ones = 0;
        if(num == 0)
            break;
         string binary = bitset<32>(num).to_string();
         string binaryWithoutTrailingZeros = "1";
         for(int i = 0; i < binary.length(); i++) {
             if(ones > 0) {
                  binaryWithoutTrailingZeros += binary[i];
             }
             if(binary[i] == '1') {
                 ones++;
             }
         }
        cout << "The parity of " << binaryWithoutTrailingZeros << " is " << ones << " (mod 2).\n"; 
    }
}