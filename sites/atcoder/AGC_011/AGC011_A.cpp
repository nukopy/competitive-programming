// AGC011_A
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
typedef long long ll;

const ll MOD7 = 1000000007;  // 1 000 000 007
const ll MOD9 = 1000000009;  // 1 000 000 009

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, capacity, K;
    cin >> N >> capacity >> K;
    vector<ll> vec(N);
    REP(i, N) cin >> vec[i];
    
    sort(vec.begin(), vec.end(), greater<>());  // int big -> small
    
    // calculation
    if (N == 2) {
        if (capacity == 1) {
            cout << 2 << "\n";
        } else if (vec[0] - vec[1] < K) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else {
        if (capacity == 1) {
            cout << N << "\n";
        } else {
            ll bus = 1;
            ll first = vec[0], now = 1;
            for (ll i = 1; i < N; ++i) {
                if (first - vec[i] <= K) {
                    if (now < capacity) {
                        now++;
                    } else if (now == capacity){
                        bus++;
                        now = 1;
                        first = vec[i];
                    }
                } else {
                    // 時間が離れていたら
                    bus++;  // 今の乗客を載せてリセット
                    now = 1;
                    first = vec[i];
                }
            }
            cout << bus << "\n";
        }
    }
    return 0;
}
