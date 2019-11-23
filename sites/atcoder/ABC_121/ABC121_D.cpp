// ABC121_D
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
const ll INF = 1LL<<60;  // 10^18

ll BinaryStr2Decimal(string &S) {
    // 10^18(long long) 程度にしか使えないので注意
    // オーバーフローに注意
    if (S == "0" || S == "1") return stoll(S);
    ll res = 0, len = S.length()-1;
    for (ll i = len; i >= 0; --i) {
        res += (S[i] == '1')? (ll)pow(2, len-i): 0;  // 2^n 指数に注意
    }
    
    return res;
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M;
    cin >> N >> M;
    
    // calculation
    if (N == M) {
        cout << N << "\n";
    } else {
        // N < M
        ll bit;
        for (ll i = 60; i >= 0; --i) {
            if (M & (1LL<<i)) {
                bit = i;
                break;
            }
        }
        
        ll BIT = (1LL<<bit), maxbit = 0;
        ll bit2;
        for (ll i = M; i >= N; --i) {
            if (!(i & BIT)) {
                // はじめて異なった時
                bit2 = i;
                break;
            }
            maxbit++;
        }
        
        vector<ll> num_vec(bit+1, 0);
        num_vec[num_vec.size()-1] = maxbit;
        
        for (ll i = 1; i <= bit; ++i) {
            ll num1 = (ll)pow(2, bit-i+1)-1;  // M >= num 1111111...
            ll num2 = (ll)pow(2, bit-i)-1;  // M >= num 1111111...
            if (N <= num2) {
                num_vec[num_vec.size()-1-i] = num1 - num2 + 1;
            } else {
                num_vec[num_vec.size()-1-i] = num1 - N + 1;
            }
        }
        num_vec[0] = ((M-N)%2 == 0 ? 1: 0);
        string str = "";
        ll num;
        REP(i, num_vec.size()) {
            num = (num_vec[i]%2 == 1 ? 1: 0);
            str = to_string(num) + str;
        }
        
        cout << BinaryStr2Decimal(str) << "\n";
    }
    
    return 0;
}