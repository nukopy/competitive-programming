// ABC032_C
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

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, K, sum = 0;
    cin >> N >> K;
    vector<ll> vec(N), part(N);
    REP(i, N) {
        cin >> vec[i];
        if (vec[i] == 0) {
            cout << N << "\n";
            return 0;
        }
        if (vec[i] <= K) sum++;
    }
    
    // calculation
    // ここで，部分列の長さが 0 or 1 のものを処理
    if (sum <= 1) {
        cout << sum << "\n";
        return 0;
    }
    
    // 部分列の長さが 2 以上のもの
    // 尺取り法
    ll right = 0;
    ll prod = 1;
    ll ans = 0;
    
    for (ll left = 0; left < N; ++left) {
        while (right < N && prod * vec[right] <= K) {
            prod *= vec[right];
            right++;
        }
        
        // ans の更新，左端を 1 縮める
        ans = max(ans, right - left);
        prod /= vec[left];
        
        if (left == right) ++right;
    }
    
    cout << ans << "\n";
    
    return 0;
}