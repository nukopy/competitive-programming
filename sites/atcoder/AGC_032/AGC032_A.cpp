// AGC032_A
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
    vector<ll> vec(N), id(N);
    REP(i, N) {
        cin >> vec[i];
        id[i] = (i+1) - vec[i];
    }
    
    // calculation
    if (N == 1) {
        if (vec[0] == 1) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else {
        // N >= 2
        // N-1 が diff のMAX
        vector<vector<ll>> diff((N-1)+1);
        for (ll i = 1; i <= N; ++i) {
            if (vec[i-1] > i) {
                cout << -1 << "\n";
                return 0;
            }
            diff[id[i-1]].push_back(vec[i-1]);
        }
        
        // ひっかからなかったら
        // 生成できる
        vector<ll> tmp, res(N+1, -1); res[0] = 1;
        ll now_diff;
        for (ll i = 0; i <= N-1; ++i) {
            now_diff = i;
            if(diff[i].empty()) continue;
            else {
                tmp = diff[i-1];
                if (tmp[0] == 0) {
                    REP(j, tmp.size()) {
                        res[tmp[j]] = tmp[j];
                    }
                } else {
                    sort(tmp.begin(), tmp.end());
                    
                }
            }
        }
        
        for (ll i = 1; i < N+1; ++i) {
            cout << res[i] << "\n";
        }
    }
    return 0;
}