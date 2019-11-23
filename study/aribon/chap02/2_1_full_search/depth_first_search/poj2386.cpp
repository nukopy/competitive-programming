#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::prev(iter, n) n 個分デクリメントしたイテレータ
#include <map>
#include <set>
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

ll n, m, res = 0;
vector<vector<char>> field;
const ll dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const ll dy[] = {1, -1, 0, 1, -1, 0, 1, -1,};

void dfs_poj2386(ll x, ll y) {
    field[x][y] = '.';  // 'W' -> '.'
    
    // 8 近傍の探索
    REP(i, 8) {
        ll next_x = x+dx[i], next_y = y+dy[i];
        if ((0 <= next_x && next_x < n) && (0 <= next_y && next_y < m)) {
            // まず，next_x と next_y が配列の範囲に収まるかチェックする
            if (field[next_x][next_y] == 'W') {
                dfs_poj2386(next_x, next_y);
            }
        }
    }
}

void POJ_2386() {
    // POJ_2386: Lake Counting
    // input
    cin >> n >> m;
    field = vector<vector<char>>(n, vector<char>(m));
    REP(i, n) REP(j, m) cin >> field[i][j];
    
    // calc
    REP(i, n) {
        REP(j, m) {
            if (field[i][j] == 'W') {
                dfs_poj2386(i, j);
                res++;
            }
        }
    }
    
    cout << res << "\n";
}

int main() {
    // 深さ優先探索
    // POJ_2386();
    
    return 0;
}