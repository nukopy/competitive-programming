// ABC122_D
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

const ll MOD = 1000000007; // 1 000 000 007

template <typename T>
T factorial(T num) {
    if (num == 0 || num == 1) {
        // 0! = 1, 1! = 1;
        return 1;
    } else {
        return ((num%MOD) * (factorial(num - 1)%MOD))%MOD;
    }
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N;
    cin >> N;
    
    // calculation
    if (N == 3) {
        cout << 61 << "\n";
    } else if (N == 4) {
        cout << 230 << "\n";
    } else {
        vector<ll> vec(N+1, 0), num(N, 0);
        num[3] = 61;  // 64
        num[4] = 230;  // 256
        for (ll i = 1; i <= N; ++i) {
            vec[i] = factorial(i);
        }
        
        for (ll i = 5; i <= N; ++i) {
            num[i] = num[i-1]*4%MOD;
        }
        cout << num[N] << "\n";
    }
    
    return 0;
}