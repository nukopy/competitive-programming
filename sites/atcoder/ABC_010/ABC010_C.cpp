// ABC010_C
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
#define vl vector<ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)


double dis(pll s, pll g) {
    return sqrt(pow(s.F - g.F, 2) + pow(s.S - g.S, 2));
}

int main() {
    // input
    ll s_x, s_y, g_x, g_y, T, V, N;
    cin >> s_x >> s_y >> g_x >> g_y >> T >> V >> N;
    vector<pll> vec(N);
    REP(i, N) cin >> vec[i].F >> vec[i].S;
    pll start = make_pair(s_x, s_y), goal = make_pair(g_x, g_y);
    
    // calculation
    double straight = T*V;
    if (N == 1) {
        if (dis(start, vec[0]) + dis(goal, vec[0]) > straight) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    } else {
        double distance;
        REP(i, N) {
            distance = dis(start, vec[i]) + dis(goal, vec[i]);
            if (EPS > fabs(straight - distance)) {
                cout << "YES" << "\n";
                return 0;
            } else if ((straight - distance) > EPS && (straight - distance) > 0) {
                cout << "YES" << "\n";
            }
        }
        cout << "NO" << "\n";
    }
    
    return 0;
}