// ABC125_C
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

unordered_map<ll, ll> mp;

template <typename T>
vector<T> divisor(T n) {
    // 約数列挙(n 自身は含まない，必要に応じて vec.push_back())
    vector<T> vec;
    for(T i = 1; i*i <= n ; ++i) {
        if (n%i == 0) {
            vec.push_back(i);
            if (i != 1 && i*i != n) {
                vec.push_back(n / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    return vec;
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    
    // calc
    ll mn = *MIN(vec);
    vector<ll> divi = divisor(mn);
    divi.push_back(mn);
    
    REP(i, N) {
        REP(j, divi.size()) {
            if (vec[i]%divi[j] == 0) mp[divi[j]]++;
        }
    }
    
    ll res = 1;
    auto begin = mp.begin(), end = mp.end();
    for (auto itr = begin; itr != end; itr++) {
        if (itr->second >= N-1) {
            res = max(res, itr->first);
        }
    }
    
    cout << res << "\n";
    
    return 0;
}