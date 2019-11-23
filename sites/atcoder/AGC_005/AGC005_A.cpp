// AGC005_A
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
typedef long long ll;

int main() {
    // input
    string X;
    cin >> X;
    
    // calculation
    if (X.length() == 2) {
        if (X == "ST") {
            cout << 0 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else {
        // 4 <= S <= 200,000, O(N^2) は無理
        // 愚直解：部分点 200 点解法
        /*
        
        int idx = (int)X.find("ST");
        while (idx != -1) {
            X.replace(idx, 2, "");
            idx = (int)X.find("ST");
        }
        cout << X.length() << "\n";
        
        */
        // 満点解法
        stack<char> stk;
        char ch;
        REP(i, X.length()) {
            ch = X[i];
            if (stk.empty()) {
                stk.push(ch);
            } else {
                if (stk.top() == 'S' && ch == 'T') {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            }
        }
        
        cout << stk.size() << "\n";
    }
    return 0;
}
