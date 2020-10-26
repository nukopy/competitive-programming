#include <iostream>
#include <string>
#include <algorithm>  // std::toupper, tolower, transform
using namespace std;
typedef long long ll;

// BEGIN CUT: a-z, A-Z を 0-25 に変換
ll alpha_to_0to25(char ch) {
    // ch 'a'-'z'
    if (islower(ch)) {
        return ch - 'a';
    } else {
        return ch - 'A';
    }
}
// END CUT

int main() {
    cout << alpha_to_0to25('a') << "\n";
    cout << alpha_to_0to25('A') << "\n";
    cout << alpha_to_0to25('l') << "\n";
    cout << alpha_to_0to25('L') << "\n";
    cout << alpha_to_0to25('z') << "\n";
    cout << alpha_to_0to25('Z') << "\n";
    return 0;
}