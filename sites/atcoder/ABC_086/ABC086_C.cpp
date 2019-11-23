// ABC086_C
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
    vector<ll> time(N);
    vector< pair<ll, ll> > plane(N);
    REP(i, N) cin >> time[i] >> plane[i].first >> plane[i].second;
    
    // calculation
    ll now_time = 0, diff_t, distance;
    pair<ll, ll> now_plane = make_pair(0, 0);
    REP(i, N) {
        diff_t = time[i] - now_time;
        distance = abs(plane[i].first - now_plane.first) + abs(plane[i].second - now_plane.second);
    
        // update time & plane
        now_time = time[i];
        now_plane = plane[i];
        
        if (distance == diff_t) {
            continue;
        } else if (distance > diff_t) {
            // 時間が足りない
            cout << "No" << "\n";
            return 0;
        } else {
            // 時間に余裕があるとき
            if ((diff_t%distance)%2 == 0) {
                continue;
            } else {
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    
    cout << "Yes" << "\n";
    
    return 0;
}
