// ABC110_D
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>  // std::copy()
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

const ll MOD = 1000000007;  // 1 000 000 007

template <typename T>
vector<T> divisor(T n) {
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
    // input
    ll N, M;
    cin >> N >> M;
    
    // calculation
    vector<ll> M_prime = divisor(M);
    M_prime.push_back(M);
    return 0;
}
