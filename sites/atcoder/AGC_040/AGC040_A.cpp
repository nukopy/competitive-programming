// AGC040_A
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
#define rep1(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define all(vec) (vec).begin(), (vec).end()
#define sum(vec) accumulate(all(vec), 0LL)  // 0 は初期値
#define min_vec(vec) min_element(all(vec))  // iterator: * を先頭につける
#define max_vec(vec) max_element(all(vec))  // iterator: * を先頭につける
#define idx(vec, element_iter) distance((vec).begin(), element_iter)
const ll INF = 1LL<<60;  // 10^18（const int inf = 1<<29;）
const double PI = acos(-1);

ll sum_retu(ll start, ll end, ll n) {
    return ((start+end)*n)/2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // input(sunippets: inpv, inpn, inps)
    string s;
    cin >> s;
    
    // calculation
    ll n = (ll)s.length();
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
        a[i + 1] = max(a[i + 1], a[i] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '>') {
        a[i] = max(a[i], a[i + 1] + 1);
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << '\n';
    return 0;
    cout << "" << "\n";
    
    return 0;
}