// ABC049_C
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
    string str;
    cin >> str;
    
    // calculation
    string five, six, seven;
    unsigned long len = str.length();
    
    if (len < 5) {
        cout << "NO" << "\n";
        return 0;
    } else if (len == 5) {
        if (str == "dream" || str == "erase") {
            cout << "YES" << "\n";
            return 0;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    } else if (len == 6) {
        if (str == "eraser") {
            cout << "YES" << "\n";
            return 0;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    } else if (len == 7) {
        if (str == "dreamer") {
            cout << "YES" << "\n";
            return 0;
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    } else {
        while (str.length() != 0) {
            five = str.substr(str.size()-1 -4, 5);
            if (five == "dream" || five == "erase") {
                str.erase(str.end()-5, str.end());
            } else {
                six = str.substr(str.size()-1 -5, 6);
                if (six == "eraser") {
                    str.erase(str.end()-6, str.end());
                } else {
                    seven = str.substr(str.size()-1 -6, 7);
                    if (seven == "dreamer") {
                        str.erase(str.end()-7, str.end());
                    } else {
                        cout << "NO" << "\n";
                        return 0;
                    }
                }
            }
        }
        cout << "YES" << "\n";
        return 0;
    }
}
