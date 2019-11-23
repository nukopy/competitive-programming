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
typedef long long ll;

int basic_1d_sum() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    /* https://qiita.com/iwakiriK/items/453cc9dc3b07f1999acc
     * 累積和で区間の合計を求める方法
     * ・N 個の入力があるとき，「N+1 個」の配列を作る
     * ・vec[0] = 0 として，入力は１オリジンにする．
     * ・求めたい区間の「(右端)-(左端より1つ左側)」を計算すると，
     * 　その区間の合計が出てくる．
    <input>
    4
    5 2 7 1
    <output>
    */
    ll N;
    cin >> N;
    vector<ll> vec(N+1), par_sum(N+1, 0);
    // １オリジンにする
    vec[0] = 0;
    par_sum[0] = 0;
    
    for (int i = 1; i < N+1; ++i) {
        cin >> vec[i];
        par_sum[i] += par_sum[i-1] + vec[i];
    }
    // vec = {0, 5, 2, 7, 1};
    // 例えば，l = 2, r = 4，のとき
    ll left = 2, right = 4;
    ll sum_2_to_4 = par_sum[right] - par_sum[left-1];
    cout << sum_2_to_4 << "\n";  // 2 + 7 + 1 = 10 が出るはず
    return 0;
}

