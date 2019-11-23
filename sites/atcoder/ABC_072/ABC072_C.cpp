#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <set>
#include <map>
#include <unordered_map>
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

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define REPN(i, n) for (ll i=1; i <= n; i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0LL)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
#define zero_pad(num) setfill('0') << std::right << setw(num)
#define space_pad(num) setfill(' ') << std::right << setw(num)

typedef long long ll;

const ll MOD7 = 1000000007;  // 1 000 000 007
const ll MOD9 = 1000000009;  // 1 000 000 009

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N), num(100010, 0);
    REP(i, N) {
        cin >> vec[i];
        num[vec[i]]++;
    }
    sort(vec.begin(), vec.end());
    
    // calculation
    if (N == 1) {
        cout << 1 << "\n";
    } else if (N == 2) {
        if ((vec[1] - vec[0]) <= 2) {
            // 1, 3 -> 2, 2  o
            // 1, 4 -> 2, 3  x
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    } else {
        ll now_renzoku, max_renzoku = 1;
        for (ll i = 0; i <= 100000; ++i) {
            if (i == 0) {
                now_renzoku = num[i] + num[i+1];
            } else if (i == 100000){
                now_renzoku = num[i-1] + num[i];
            } else {
                now_renzoku = num[i-1] + num[i] + num[i+1];
            }
            max_renzoku = max(max_renzoku, now_renzoku);
        }
        
        cout << max_renzoku << "\n";
    }
    
    return 0;
}
