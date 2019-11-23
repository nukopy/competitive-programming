// AGC022_A
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <bitset>  // static_cast<std::bitset<8>>
#include <sstream>  // std::stringstream
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>  // std::setprecision()
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値
#define vl vector<ll>

int main() {
    // input
    string S;
    cin >> S;
    vl alpha(26, 0);
    
    // calculation
    
    if (S.length() < 26) {
        REP(i, S.length()) {
            alpha[(ll)(S[i] - 'a')]++;
        }
        
        REP(i, 26) {
            if (alpha[i] == 0) {
                S += (char)(i + 'a');
                break;
            }
        }
        cout << S << "\n";
    } else {
        if (S == "zyxwvutsrqponmlkjihgfedcba") {
            cout << -1 << "\n";
        } else {
            // 上以外は何かしら次に小さい文字列がある
            char res_ch;
            string sub;
            for (ll i = 26-1; i >= 0; --i) {
                sub = S.substr(i);
                if (next_permutation(sub.begin(), sub.end())) {
                    // 回転できる文字列が見つかった時
                    for (ll j = 0; j <= i; ++j) {
                        alpha[(ll)(S[j]-'a')]++;
                    }
                    
                    REP(j, 26) {
                        if (alpha[j] == 0 && S[i] < (char)(j + 'a')) {
                            res_ch = (char)(j + 'a');
                            cout << S.substr(0, i) << res_ch << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}