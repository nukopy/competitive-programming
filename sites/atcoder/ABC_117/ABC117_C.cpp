// ABC117_C
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <set>
#include <map>
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
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll koma, num_pos;
    cin >> koma >> num_pos;
    vector<ll> positions(num_pos);
    REP(i, num_pos) cin >> positions[i];
    
    // calculation
    if (koma == 1) {
        cout << *MAX(positions) - *MIN(positions) << "\n";
    } else if (num_pos == 1) {
        cout << 0 << "\n";
    } else if (koma >= num_pos){
        cout << 0 << "\n";
    } else {
        sort(positions.begin(), positions.end());  // down ->
        vector<ll> diff(num_pos-1);
        for (ll i = 1; i < num_pos; ++i) {
            diff[i-1] = positions[i] - positions[i-1];
        }
        
//        // 両端から駒を抜いていく (koma-1)個分
//        ll id_front = 0, id_back = num_pos-2;
//        REP(i, koma-1) {
//            if (diff[id_front] >= diff[id_back]) {
//                id_front++;
//            } else {
//                id_back--;
//            }
//        }
//
//        // last
        ll sum = 0;
//        for (ll j = id_front; j <= id_back; ++j) {
//            sum += diff[j];
//        }

        sort(diff.begin(), diff.end());
        for (int j = 0; j < num_pos-1-koma+1; ++j) {
            sum += diff[j];
        }
        cout << sum << "\n";
    }
    
    return 0;
}
