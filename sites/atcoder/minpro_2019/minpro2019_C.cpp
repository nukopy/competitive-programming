// minpro2019_C
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
    ll K, A, B;
    cin >> K >> A >> B;
    
    // calculation
    if (K == 1) {
        // ビスケットを叩いて＋１で２枚
        cout << 2 << "\n";
    } else if (K == 2) {
        // たたくのみ or 1回交換する
        // B = 1 でも良い．どうせ増やせないから
        cout << std::max(ll(1+2), B) << "\n";
    } else if (K >= 3){
        ll bis = 1;
        if (K < A - bis + 2) {
            // 1回も交換できないとき
            cout << 1 + K << "\n";
        } else if (K == A - bis + 2) {
            // ぴったり1回だけ交換できるとき
            cout << max(1+K, B) << "\n";
        } else {
            // 1回以上交換できるとき
            // 1回目
            bis = max(1 + (A-1) + 2, B);
            K -= (A - 1) + 2;
            
            // 2回目以降
            if (A + 2 >= B) {
                // 交換が得じゃないとき
                cout << bis + K << "\n";
            } else {
                // 交換が得なとき: (A + 2) < B
                ll max_times, nokori, possible_times;
                while (K >= 2) {
                    max_times = bis/A;  // 何回交換できるか
                    nokori = A - bis%A;
                    if (K >= max_times*2) {
                        bis += max_times*(B - A);
                        K -= 2 * max_times;  // 交換には２倍の回数が必要
                        
                    } else {
                        bis += (K/2)*(B-A);
                        K -= 2 * (K/2);
                        
                        bis += K%2;
                        K -= K%2;
                    }
                }
                
                // K = 1 or 0
                cout << bis + K << "\n";
                
            }
        }
    }
    return 0;
}
