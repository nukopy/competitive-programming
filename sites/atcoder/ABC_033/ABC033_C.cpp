// ABC033_C
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

const int MOD = 1000000007;  // 1 000 000 007
ll ctoi(char c){
    if('0' <= c && c <= '9') return (c-'0');
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    string str;
    cin >> str;
    
    // + と * だけ
    size_t len = str.length();
    if (len == 1) {
        if (str[0] == '0') cout << 0 << "\n";
        else cout << 1 << "\n";
    } else {
        vector<ll> nums;
        vector<char> ope;
        for (size_t i = 0; i < len; ++i) {
            if (i % 2 == 0) nums.push_back(ctoi(str[i]));
            else ope.push_back(str[i]);
        }
        
        vector<ll> vec;
        vec.push_back(nums[0]);
        ll idx = 0;
        for (ll i = 1; i < nums.size(); ++i) {
            if (ope[i - 1] == '*') {
                vec[idx] = vec[idx] * nums[i];
            } else {
                vec.push_back(nums[i]);
                idx++;
            }
        }
        
        ll sum = 0;
        for (ll i = 0; i < vec.size(); ++i) {
            if (vec[i] != 0) sum++;
        }
        cout << sum << "\n";
    }
    return 0;
}
