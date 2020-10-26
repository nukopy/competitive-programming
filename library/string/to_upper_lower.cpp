// ABC059_A
#include <iostream>
#include <string>
#include <algorithm>  // std::toupper, tolower, transform
using namespace std;
typedef long long ll;

// BEGIN CUT to upper-case
char toupper_char(char ch) {
    // (char)(ch - 32)
    return (char)toupper(ch);
}
string toupper_string(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
// END CUT

// BEGIN CUT to lower-case
char tolower_char(char ch) {
    // (char)(ch - 32)
    return (char)tolower(ch);
}
string tolower_string(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
// END CUT

// BEGIN CUT up2low & low2up
string up2low_low2up (string str) {
    for (ll i = 0; i < str.length(); ++i) {
        // 大文字を小文字，小文字を大文字
        if (isupper(str[i])) {
            str[i] = (char)tolower(str[i]);
        } else {
            str[i] = (char)toupper(str[i]);
        }
    }
    return str;
}
// END CUT

int test_toupper() {
    cout << "----- test toupper -----" << "\n";
    
    // test: toupper
    char ch_lower = 'w';
    cout << ch_lower << " -> " << toupper_char(ch_lower) << "\n";
    
    string str_lower = "CompetitveProgramming";
    cout << str_lower << " -> " << toupper_string(str_lower) << "\n";
    
    cout << "\n";
    return 0;
}

int test_tolower() {
    cout << "----- test tolower -----" << "\n";
    
    // test: tolower
    char ch_upper = 'W';
    cout << ch_upper << " -> " << tolower_char(ch_upper) << "\n";
    
    string str_upper = "ATCODER";
    cout << str_upper << " -> " << tolower_string(str_upper) << "\n";
    
    cout << "\n";
    return 0;
}

int test_up2low_low2up() {
    cout << "----- test up2low_low2up -----" << "\n";
    string str = "AtCoder Beginner Selection", str1 = "HOgehoGE";
    
    cout << str << " -> " << up2low_low2up(str) << "\n";
    cout << str1 << " -> " << up2low_low2up(str1) << "\n";
    
    cout << "\n";
    
    return 0;
}

// verified
int main() {
    // tests
    test_toupper();
    test_tolower();
    test_up2low_low2up();
    
    return 0;
}

/*
----- test toupper -----
w -> W
CompetitveProgramming -> COMPETITVEPROGRAMMING

----- test tolower -----
W -> w
ATCODER -> atcoder

----- test up2low_low2up -----
AtCoder Beginner Selection -> aTcODER bEGINNER sELECTION
HOgehoGE -> hoGEHOge
*/