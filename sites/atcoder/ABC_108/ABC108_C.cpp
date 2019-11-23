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

int main() {
    // input
    ll N, K;
    cin >> N >> K;
    
    // calculation
    if (N == 1) {
        // (1, 1, 1) のみ
        if (2%K == 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {
        // (a, b, c) をKで割った余りの和が，
        // 0: 全て K の倍数のとき
        // K: (2, 8) 2%5 = 2, 8%5 = 3, (2+3) = 5
        ll res = 0;
        
        // a, b, c 全てが K の倍数の時
        // N=9, K=3, (3, 3, 3), (6, 6, 6), (9, 9, 9) 
        // 余りの和が K のとき
        // K が奇数の時：
        
        if (K%2 != 0) {
            // K が奇数の時
            res += pow((N/K), 3);
        } else {
            // K が偶数の時
            res += pow((N/K), 3);
            ll sum = 0;
            for (ll i = 1; i <= N; ++i) {
                if (i%K == K/2) {
                    sum++;
                }
            }
            
            if (sum != 0) res += pow(sum, 3);
        } 
        
        cout << res << "\n";
    }
    return 0;
}