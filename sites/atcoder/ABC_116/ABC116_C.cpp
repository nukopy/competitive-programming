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

int first() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;
    vector<ll> height(N);
    REP(i, N) cin >> height[i];
    
    // calculation
    if (N == 1) {
        cout << height[0] << "\n";
    } else {
        ll idx = 0, left, right, min_interval;
        ll sum_height = SUM(height), res = 0;
        while (sum_height > 0) {
            // 区間を定める
            left = -1, right = -1;
            min_interval = 101;
    
            // 左端を定める
            for (ll i = 0; i < N; ++i) {
                if (height[i] != 0) {
                    left = i;
                    break;
                }
            }
            
            if (left == -1) {
                // 全てが 0 の場合
                break;
            } else {
                // 右端を定める
                for (ll i = left; i < N; ++i) {
                    if (height[i] != 0) {
                        min_interval = min(min_interval, height[i]);
                        right = i;
                    } else {
                        break;
                    }
                }
                
                if (left == right) {
                    // 順序気をつける
                    res += height[left];
                    sum_height -= height[left];
                    height[left] -= min_interval;
                } else {
                    for (ll i = left; i <= right; ++i) {
                        height[i] -= min_interval;
                        sum_height -= min_interval;
                    }
                    res += min_interval;
                }
            }
        }
        
        cout << res << "\n";
    }
    
    return 0;
}

int other() {
    ll N;
    cin >> N;
    vector<ll> height(N);
    for (ll i = 0; i < N; ++i) cin >> height[i];
    
    ll sum = height[0];
    for (ll i = 0; i < N-1; ++i) {
        sum += max((ll)0, height[i+1] - height[i]);
    }
    
    cout << sum << "\n";
}

int main() {
    other();
    return 0;
}