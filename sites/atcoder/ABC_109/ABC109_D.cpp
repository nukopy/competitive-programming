// ABC109_D
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
    ll N, M, sum = 0;
    cin >> N >> M;
    vector< vector<ll> > vec((size_t)N, vector<ll>((size_t)M));
    REP(i, N) {
        // N 行
        REP(j, M) {
            // M 列：入力が逆になることもあるので注意
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }
    
    // calculation
    ll res_num = 0;
    vector< vector<ll> > res;
    
    REP(i, N-1) {
        REP(j, M) {
            if (vec[i][j]%2 != 0) {
                // 奇数の時後ろに押し付ける
                vec[i][j]--;
                vec[i+1][j]++;
                vector<ll> tmp = {i+1, j+1, (i+1)+1, j+1};
                res.emplace_back(tmp);
                res_num++;
            }
        }
    }
    
    REP(i, M-1) {
        if (vec[N-1][i]%2 != 0) {
            vec[N-1][i]--;
            vec[N-1][i+1]++;
            vector<ll> tmp = {N, i+1, N, (i+1)+1};
            res.emplace_back(tmp);
            res_num++;
        }
    }
    
    cout << res_num << "\n";
    REP(i, res.size()) {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << "\n";
    }
    
    return 0;
}
