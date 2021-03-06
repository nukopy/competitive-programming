// nikkei_procon2019_D
// nikkei_procon2019_C
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <set>
#include <map>
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
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    ll N;
    cin >> N;
    vector<ll> Taka(N), Aoki(N), diff(N), diff_reverse(N); //diff_cp(N)
    REP(i, N) {
        cin >> Taka[i] >> Aoki[i];
    }
    
    // calculation
    ll d;
    REP(i, N) {
//        d = abs(Taka[i] - Aoki[i]);
        d = Taka[i] - Aoki[i];
        diff[i] = d;
        diff_reverse[i] = -d;
    }
    
    if (N == 1) {
        cout << Taka[0] << "\n";
    } else {
        ll Ta = 0, Ao = 0;
        sort(Taka.begin(), Taka.end(), greater<ll>());  // int big -> small
        
        
        REP(i, N) {
            if (i%2 == 0) {
                Ta += Taka[i];
            }
        }
        
    }
    
    return 0;
}
