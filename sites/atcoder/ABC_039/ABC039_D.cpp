// ABC039_D
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
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

int main() {
    // input
    ll H, W;
    cin >> H >> W;
    vector<string> vec(H);
    REP(i, H) cin >> vec[i];
    
    // calculation
    // .: white, #: black
    // 後ろ，前，上，下，斜め左上，斜め右上，斜め左下，斜め右下
    vector<ll> h = {0, 0, -1, +1, -1, -1, +1, +1};
    vector<ll> w = {-1, +1, 0, 0, -1, +1, -1, +1};
    ll now_h, now_w, area;
    vector< pair<ll, ll> > pos;
    pair<ll, ll> plane;
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            if (vec[i][j] == '#') {
                area = 0;
                for (ll k = 0; k < 8; ++k) {
                    now_h = i + h[k];
                    now_w = j + w[k];
                    if (0 <= now_h && now_h <= H-1 && 0 <= now_w && now_w <= W-1) {
                        if (vec[now_h][now_w] == '#') area++;
                    }
                }
                
                if ((i == 0 || i == H-1) && (j == 0 || j == W-1) && area == 3 ) {
                    pos.emplace_back(i, j);
                } else if ((((i == 0 || i == H-1) && (j != 0 || j != W-1)) || ((i != 0 || i != H-1) && (j == 0 || j == W-1))) && area == 5) {
                    pos.emplace_back(i, j);
                } else if (area == 8) {
                    pos.emplace_back(i, j);
                }
            }
        }
    }
    
    vector<string> origin(H, "");
    REP(i, H) {
        REP(i, W) {
            origin[i] += '.';
        }
    }
    vector<string> copy = origin;
    REP(i, pos.size()) {
        origin[pos[i].first][pos[i].second] = '#';
        copy[pos[i].first][pos[i].second] = '#';
        REP(j, 8) {
            now_h = pos[i].first + h[j];
            now_w = pos[i].second + w[j];
            if ((0 <= now_h && now_h <= H-1) && (0 <= now_w && now_w <= W-1)) {
                copy[now_h][now_w] = '#';
            }
        }
    }
    
    bool flag = true;
    REP(i, H) {
        REP(j, W) {
            if (vec[i][j] != copy[i][j]) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) {
        cout << "possible" << "\n";
        REP(i, H) {
            cout << origin[i] << "\n";
        }
    } else {
        cout << "impossible" << "\n";
    }
    
    return 0;
}