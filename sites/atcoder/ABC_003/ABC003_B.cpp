// ABC003_B
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
    string N, M;
    cin >> N >> M;
    
    REP(i, N.length()) {
        if (N[i] == M[i]) {
            continue;
        } else {
            // 等しくないとき
            if (N[i] == '@') {
                if (M[i] == 'a' || M[i] == 't' ||M[i] == 'c' ||M[i] == 'o' ||M[i] == 'd' ||M[i] == 'e' ||M[i] == 'r') {
                    continue;
                } else {
                    cout << "You will lose" << "\n";
                    return 0;
                }
            } else if (M[i] == '@') {
                if (N[i] == 'a' || N[i] == 't' ||N[i] == 'c' ||N[i] == 'o' ||N[i] == 'd' ||N[i] == 'e' ||N[i] == 'r') {
                    continue;
                } else {
                    cout << "You will lose" << "\n";
                    return 0;
                }
            } else {
                cout << "You will lose" << "\n";
                return 0;
            }
        }
    }
    
    cout << "You can win" << "\n";
    
    return 0;
}