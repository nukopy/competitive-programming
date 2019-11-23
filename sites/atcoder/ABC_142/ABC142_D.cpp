// ABC142_D
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

//CUT HERE BEGIN ysys13
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
    vec.push_back(n);
    return vec;
}
//CUT HERE END

template <typename T>
T gcd(T a, T b) {
    if (a <= 0 || b <= 0) {
        // どちらかが 0 以下であれば -1 を返す
        return -1;
    } else if (a == 1 || b == 1) {
        // どちらかが 1 であれば，最大公約数は 1
        return 1;
    } else {
        if (a < b) swap(a, b);
        if (a%b == 0) return b;
        return gcd(b, a%b);
    }
}

//BEGIN CUT HERE
template <typename T>
T isPrime(T x){
    if(x <= 1) {
        // 0，1は素数じゃない
        return 0;
    } else if (x == 2) {
        // 2は素数
        return 1;
    } else if (x%2 == 0) {
        // 偶数は除く
        return 0;
    } else {
        // 偶数は２で割り切れるため除く
        for(T i = 3; i*i <= x; i+=2) {
            if(x%i == 0) return 0;
        }
        return 1;
    }
}
//END CUT HERE

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll A, B;
    cin >> A >> B;
    
    // calculation
    vector<ll> fac_A = divisor(A);
    vector<ll> fac_B = divisor(B);
    set<ll> fac_AB;
    
    REP(i, fac_A.size()) {
        REP(j, fac_B.size()) {
            if (fac_A[i] == fac_B[j]) {
                fac_AB.insert(fac_A[i]);
            }
        }
    }
    
    ll res = 1;
    auto begin = fac_AB.begin(), end = fac_AB.end();
    for (auto iter = begin; iter != end; iter++) {
        if (isPrime(*iter)) res++;
    }
    
    cout << res << "\n";
    
    return 0;
}