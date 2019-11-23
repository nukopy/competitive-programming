// Tenka1_Beginner2019_C
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    string S;
    cin >> S;
    
    // calculation
    // .: white
    // #: black
    if (N == 1) {
        cout << 0 << "\n";
    } else {
        ll startB = -1, endW = -1;
        
        // 左から読んで，最初にブラックが出たらbreak
        for (ll i = 0; i < N; ++i) {
            if (S[i] == '#') {
                startB = i;
                break;
            }
        }
        // 右から読んで最初に white が出てきたらストップ
        for (ll i = N-1; i >= 0; --i) {
            if (S[i] == '.') {
                endW = i;
                break;
            }
        }
        
        // idx_lastW < idx_lastB という関係
        if (startB == -1 || endW == -1) {
            // 白のみだったとき
            // 黒のみだったとき
            cout << 0 << "\n";
        } else {
            // 白黒存在するとき
            ll black = 0, white = 0;
            for (ll i = startB; i <= endW; ++i) {
                if (S[i] == '#') {
                    black++;
                } else {
                    white++;
                }
            }
            ll one_res = min(black, white);
            
            // 分断する点を見つける
            ll out_white = (startB == 0 ? 0: startB-1);
            ll out_black = (endW == N-1 ? 0: (N-1)-endW);
            ll res = min({one_res, min(out_white+white, out_black+black), out_white+out_black});
            cout << res << "\n";
            
        }
    }
    return 0;
}