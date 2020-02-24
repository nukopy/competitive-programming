// ABC155_E
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    // input(sunippets: inpv, inpn, inps)
    ll N, K;
    cin >> N >> K;
    vector<ll> vec(N), plus_vec, minus_vec;
    ll plus = 0, minus = 0, zero = 0;  // 和が N になっている
    rep(i, N) {
        cin >> vec[i];
        if (vec[i] == 0) zero++;
        if (vec[i] > 0) {
            plus++;
            plus_vec.push_back(vec[i]);
        }
        if (vec[i] < 0) {
            minus++;
            minus_vec.push_back(vec[i]);
        }
    }
    sort(vec.begin(), vec.end());
    sort(plus_vec.begin(), plus_vec.end());
    sort(minus_vec.begin(), minus_vec.end());
    
    // calculation
    // ペアの積のうち，
    // 全てを計算することはできないが，
    // それぞれの符号の数がどれだけ現れるかは計算できる
    ll pair_num_plus = 0;
    ll pair_num_minus = 0;
    ll pair_num_zero = 0;
    
    // + の数
    // (+, +) or (-, -)
    pair_num_plus = (plus*(plus-1))/2 + (minus*(minus-1))/2;
    
    // - の数
    // (+, -)
    pair_num_minus = minus*plus;
    
    // 0 の数
    // (0, +), (0, -), (0, 0)
    pair_num_zero = zero*plus + zero*minus + (zero*(zero-1))/2;
    
    // pair_{hoge} の合計が N(N-1)/2 になるはず
    
    // ここまでの計算で，
    // （- の数）,(0 の数),(+ の数)という大まかな構造が分かる
    if (1 <= K && K <= pair_num_minus) {
        // K の位置はマイナス
        ll idx;
        for (ll i = 1; i <= minus_vec.size(); ++i) {
            if (i*2 <= K && K <= i*2 + plus_vec.size()) {
                idx = i;
                break;
            }
        }
        ll res_idx = K-(idx*2);
        ll res = minus_vec[idx] * plus_vec[res_idx];
        cout << res << "\n";
    } else if (pair_num_minus < K && K <= pair_num_minus + pair_num_zero) {
        // K の位置は 0
        cout << 0 << "\n";
        return 0;
    } else {
        // K の位置はプラス
        ll idx_plus;
        for (ll i = 1; i <= plus_vec.size(); ++i) {
            if (i*2 <= K && K <= i*2 + plus_vec.size()) {
                idx_plus = i;
                break;
            }
        }
        
        ll idx_minus;
        for (ll i = 1; i <= minus_vec.size(); ++i) {
            if (i*2 <= K && K <= i*2 + minus_vec.size()) {
                idx_minus = i;
                break;
            }
        }
    }
    
    return 0;
}
