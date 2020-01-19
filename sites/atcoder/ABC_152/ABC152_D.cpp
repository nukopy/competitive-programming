// ABC152_D
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
#include <cstring>  // std::memset
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
#include <iomanip>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define repr(i, n) for (ll i=n-1; i >= 0; i++)  // n-1 ~ 0
#define rep1(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define all(vec) (vec).begin(), (vec).end()
#define sum(vec) accumulate(all(vec), 0LL)  // 0 は初期値
#define min_vec(vec) min_element(all(vec))  // iterator: * を先頭につける
#define max_vec(vec) max_element(all(vec))  // iterator: * を先頭につける
#define idx(vec, element_iter) distance((vec).begin(), element_iter)
const ll INF = 1LL<<60;  // 10^18（const int inf = 1<<29;）
const double PI = acos(-1);

ll dp[20010][2][2];

pll getLeftRightDigit(ll n) {
    // 左端（最大位），右端（最小位）の数字を取得
    string n_str = to_string(n);
    ll first = (ll)(n_str.front() - '0');
    ll second = (ll)(n_str.back() - '0');  // n%10 でも OK
    return pll(first, second);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    
    // calculation
    // 数字のペアの数を前処理として計算
    map<pll, ll> mp;
    rep1(i, N) {
        pll p = getLeftRightDigit(i);
        mp[p]++;
    }
    
    // 各ペアの集計値の積を足していく：(1, 9), (9, 1)
    ll res = 0;
    for (ll i = 1; i <= 9; i++) {
        for (ll j = 1; j <= 9; j++) {
            pll a(i, j), b(j, i);
            res += mp[a] * mp[b];
        }
    }
    
    /*
    これでも行ける
    for (ll i = 1; i <= N; ++i) {
        pll p = getLeftRightDigit(i);
        pll q(p.second, p.first);
        res += mp[q];
    }
    */
    
    cout << res << "\n";
    
    return 0;
}

/*



*/