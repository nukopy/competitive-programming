// ABC038_D
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
    ll N, w_i, h_i;
    cin >> N;
    vector< tuple<ll, ll> > box(N), box_r(N), b;
    for (ll i = 0; i < N; ++i) {
        cin >> w_i >> h_i;
        box[i] = make_tuple(w_i, h_i);
        box_r[i] = make_tuple(h_i, w_i);
    }
    sort(box.begin(), box.end(), greater<>());  // int big -> small
    sort(box_r.begin(), box_r.end(), greater<>());  // int big -> small
    
    // calculation
    // width 大きい順
    stack< tuple<ll, ll > > st1, st2, st;
    st1.push(box[0]); st2.push(box_r[0]);
    ll top_w, top_h, res = 0;
    for (ll i = 0; i < 2; ++i) {
        if (i == 0) {
            st = st1;
            b = box;
        } else {
            st = st2;
            b = box_r;
        }
        
        for (ll i = 1; i < N; ++i) {
            w_i = get<0>(b[i]);
            h_i = get<1>(b[i]);
            
            top_w = get<0>(st.top());
            top_h = get<1>(st.top());
            
            if (w_i < top_w && h_i < top_h) {
                st.emplace(w_i, h_i);
            } else if ((w_i == top_w && h_i > top_h) || (w_i > top_w && h_i == top_h)) {
                // より大きい方に入れ替える
                st.pop();
                st.emplace(w_i, h_i);
            }
        }
        res = max(res, (ll)st.size());
    }
    
    cout << res << "\n";
    
    return 0;
}