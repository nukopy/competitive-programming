// ABC064_D
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
#define pll pair<ll, ll>
#define F first
#define S second

int main() {
    // input
    ll N;
    string S;
    cin >> N >> S;
    
    // calculation
    if (N == 1) {
        cout << "()" << "\n";
    } else if (N == 2) {
        if (S == "()") {
            cout << "()" << "\n";
        } else if (S == "((" || S == "))") {
            cout << "(())" << "\n";
        } else if (S == ")(") {
            cout << "()()" << "\n";
        }
    } else {
        vector<ll> left(N, 0), right(N, 0);
        REP(i, N) {
            if (S[i] == '(') left[i]++;
            else right[i]++;
        }
        
        partial_sum(left.begin(), left.end(), left.begin());
        partial_sum(right.begin(), right.end(), right.begin());
        
        // ')' のペアを探す
        ll need_left = 0, need_right = 0;
        ll idx = 0, l = 0, r = 0;
        bool flag;
        while (idx != N) {
            flag = true;
            // ')' とのペアを探す
            if (S[idx] == ')') {
                r++;
            } else {
                if (l == 0) {
                    need_left += r;  // ここまでの r を足す
                } else {
                    // ')' の方が少なかったら 0
                    need_left += max(r - l, 0LL);
                }
                r = 0;  // 初期化
                l = 1;
                flag = false;
            }
            idx++;
        }
        if (flag) need_left += max(r - l, 0LL);
        
        idx = N-1, l = 0, r = 0;
        while (idx >= 0) {
            flag = false;
            // ')' とのペアを探す
            if (S[idx] == '(') {
                l++;
            } else {
                if (r == 0) {
                    need_right += l;  // ここまでの l を足す
                } else {
                    // '(' の方が少なかったら 0
                    need_right += max(l - r, 0LL);
                }
                l = 0;  // 初期化
                r = 1;
                flag = false;
            }
            idx--;
        }
        if (flag) need_right += max(l - r, 0LL);
        
        REP(i, need_left) cout << '(';
        cout << S;
        REP(i, need_right) cout << ')';
        cout << "\n";
        
    }
    return 0;
}
