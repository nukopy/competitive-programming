// AGC039_A
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::prev(iter, n) n 個分デクリメントしたイテレータ
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
#include <cstring>  // std::memset 初期化
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>  // std::setprecision()
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値
#define F first
#define S second
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    string S;
    cin >> S;
    ll K;
    cin >> K;
    char s = S[0];
    ll check_all = 1;
    for (ll i = 1; i < S.size(); ++i) if (s == S[i]) check_all++;
    
    // calculation
    if (check_all == (ll)S.size()) {
        // 全部同じ文字のとき
        if (check_all%2 == 0) {
            cout << (check_all*K)/2 << "\n";
        } else {
            // 文字数が奇数のとき
            if (K%2 == 0) {
                // 最終的な文字数が偶数
                cout << (check_all*K)/2 + 1 << "\n";
            } else {
                // 最終的な文字数が奇数
                cout << (check_all*K)/2 << "\n";
            }
        }
    } else {
        vl vec;
        char ch = S[0];
        ll cnt = 1;
        for (ll i = 1; i < S.size(); ++i) {
            if (ch == S[i]) {
                cnt++;
            } else {
                vec.push_back(cnt);
                cnt = 1;
                ch = S[i];
            }
        }
        vec.push_back(cnt);
        
        if (S.front() != S.back()) {
            ll ans = 0;
            REP(i, vec.size()) {
                ans += vec[i]/2;
            }
            ans *= K;
            cout << ans << "\n";
        } else {
            // 内側を計算
            ll inner = 0;
            for (ll i = 1; i < (ll)vec.size()-1; ++i) {
                inner += vec[i]/2;
            }
            inner *= K;
            
            // 外側を計算
            // aaaeeaaa
            ll outer = 0;
            outer += vec.front()/2 + vec.back()/2;
            outer += ((vec.front()+vec.back())/2)*(K-1);
        
            cout << inner + outer << "\n";
        }
    }
    
    return 0;
}

// c ooooooooo nt eeeeeeeeee st
// 9, 10
// 奇数の場合は 9/2, 偶数の場合は 10/2