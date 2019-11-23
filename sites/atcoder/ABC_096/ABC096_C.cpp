// ABC096_C
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

ll x[] = {0, 0, 1, -1};
ll y[] = {1, -1, 0, 0};

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll H, W;
    cin >> H >> W;
    vector<string> vec(H);
    REP(i, H) cin >> vec[i];
    
    // calculation
    bool flag = true;
    ll sum;
    REP(i, H) {
        REP(j, W) {
            if (vec[i][j] == '#') {
                sum = 0;
                REP(l, 4) {
                    ll yy = i+y[l], xx = j+x[l];
                    if ((0 <= yy && yy <= H-1) && (0 <= xx && xx <= W-1)) {
                        if (vec[yy][xx] == '#') sum++;
                    }
                }
                
                if (sum == 0) {
                    flag = false;
                    break;
                }
            }
        }
    }
    
    if (flag) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    
    return 0;
}