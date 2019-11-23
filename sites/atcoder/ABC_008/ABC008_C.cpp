// ABC008_C
#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <tuple>  // std::tuple std::get
#include <map>
#include <unordered_map>
#include <set>
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
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1
#define MIN(vec) min_element(vec.begin(), vec.end())  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(vec.begin(), vec.end())
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(vec.begin(), vec.end(), 0LL)  // 0 は初期値

int main() {
    // input
    ll N;
    cin >> N;
    vector<ll> vec(N);
    map<ll, ll> mp, mp_count;
    REP(i, N) {
        cin >> vec[i];
        mp.insert(make_pair(vec[i], 0));
        mp_count.insert(make_pair(vec[i], 0));
    }
    
    // 各数を数える
    REP(i, N) {
        mp_count[vec[i]]++;
    }
    
    // calculation
    ll numerator, denominator;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            if (i == j) continue;
            numerator = vec[i];
            denominator = vec[j];
            if (numerator%denominator == 0) {
                mp[numerator]++;
            }
        }
    }
    
    double res = 0;
    ll num, den, now_num;
    auto begin = mp.begin(), end = mp.end();
    for (auto itr = begin; itr != end; itr++) {
        now_num = mp_count[itr->first];
        num = ((itr->second/ now_num + 1) + 1)/2;
        den = (itr->second / now_num) + 1;
        
        res += (now_num == 1)? (double)num/(double)den: ((double)num/(double)den)*now_num;
    }
    
    cout << setprecision(3+10) << res << "\n";
    
    return 0;
}
