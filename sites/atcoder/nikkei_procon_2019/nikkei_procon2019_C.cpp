// nikkei_procon2019_C
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <set>
#include <map>
#include <tuple>  // std::tuple std::get
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
    ll N, taka, aoki;
    cin >> N;
    vector<tuple<ll, ll, ll>> vec(N);
    REP(i, N) {
        cin >> taka >> aoki;
        vec[i] = make_tuple(taka, aoki, taka+aoki);
    }
    
    sort(vec.begin(), vec.end(),
        [](tuple<ll , ll , ll> &front_tup, tuple<ll , ll , ll> &back_tup) {
            return get<2>(front_tup) > get<2>(back_tup);
        }
    );
    
    // calculation
    taka = aoki = 0;
    REP(i, N) {
        if (i%2 == 0) {
            taka += get<0>(vec[i]);
        } else {
            aoki += get<1>(vec[i]);
        }
    }
    cout << taka - aoki << "\n";
    
    return 0;
}
