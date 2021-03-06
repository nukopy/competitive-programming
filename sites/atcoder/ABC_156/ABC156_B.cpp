// ABC156_B
#include <algorithm>
#include <bitset>  // static_cast<std::bitset<8>>
#include <cctype>  // std::isdigit()
#include <climits>  // INT_MIN
#include <cmath>
#include <cstring>  // std::memset
#include <functional>  // std::greater<T>()
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <sstream>  // std::stringstream
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>  // std::swap()
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pll;
#define rep(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define rep1(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define repr(i, n) for (ll i=n-1; i >= 0; i++)  // n-1 ~ 0
#define all(vec) (vec).begin(), (vec).end()
#define sum(vec) accumulate(all(vec), 0LL)  // 0 は初期値
#define min_vec(vec) min_element(all(vec))  // iterator: * を先頭につける
#define max_vec(vec) max_element(all(vec))  // iterator: * を先頭につける
#define idx(vec, element_iter) distance((vec).begin(), element_iter)
const ll INF = 1LL<<60;  // 10^18（const int inf = 1<<29;）
const double PI = acos(-1);

ull Decimal2BinaryStr(ull n, ull K) {
    // 10^18(long long) 程度にしか使えないので注意
    if (n == 0 || n == 1) return 1;
    ull res = 0, cnt = 0;
    while (n != 0) {
        res += (n%K)*(ull)pow(10, cnt);  // 10進数で数字をつくる
        n /= K;
        cnt++;
    }
    return cnt;
}
// 10011 00010 01011 01000 0000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    // input(sunippets: inpv, inpn, inps)
    ull N, M;
    cin >> N >> M;
    
    // calculation
    ull res = Decimal2BinaryStr(N, M);
    cout << res << "\n";
    
    return 0;
}
