// ABC074_C
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
    ll water_A, water_B, sugar_C, sugar_D, yokai, max_gram;
    cin >> water_A >> water_B >> sugar_C >> sugar_D >> yokai >> max_gram;
    
    // calculation
    if (water_A*100 > max_gram) {
        // 起こりえない
    } else if (water_A * 100 == max_gram) {
        // 最低限入る水とマックスが同じ時
        // 砂糖水 = water_A*100, 砂糖の質量 = 0
        cout << water_A*100 << 0 << "\n";
    } else if (water_A < max_gram){
        vector<ll> water, sugar;
        ll max_A = max_gram/water_A, max_B = max_gram/water_B;
        ll max_C = max_gram/sugar_C, max_D = max_gram/sugar_D;
        // 水を列挙
        for (ll i = 0; i <= max_A; ++i) {
            for (ll j = 0; j <= max_B; ++j) {
                ll A = i*100*water_A, B = j*100*water_B;
                if (A + B <= max_gram) {
                    water.push_back(A+B);
                }
            }
        }
        
        // 砂糖を列挙
        for (ll i = 0; i <= max_C; ++i) {
            for (ll j = 0; j <= max_D; ++j) {
                ll C = i*sugar_C, D = j*sugar_D;
                if (C + D <= max_gram) {
                    sugar.push_back(C+D);
                }
            }
        }
        
        // sort and unique
        sort(water.begin(), water.end());
        sort(sugar.begin(), sugar.end());
        water.erase(unique(water.begin(), water.end()), water.end());  // MUST sort before unique
        sugar.erase(unique(sugar.begin(), sugar.end()), sugar.end());  // MUST sort before unique
        
        // 全列挙
        ll sugar_space;
        ll now_water, now_sugar, now_yokaido;
        double conc = -1, now_conc;
        ll res_water, res_sugar;
        REP(i, water.size()) {
            REP(j, sugar.size()) {
                now_water = water[i];
                now_sugar = sugar[j];
                now_yokaido = (now_water/100) * yokai;
                sugar_space = min(max_gram - now_water, now_yokaido);
                if (sugar_space >= now_sugar) {
                    // 砂糖が入る時
                    now_conc = (double)(100*now_sugar)/(double)(now_water + now_sugar);
                    if (conc < now_conc) {
                        res_water = now_water;
                        res_sugar = now_sugar;
                        conc = now_conc;
                    }
                }
            }
        }
        cout << res_water + res_sugar << " " << res_sugar << "\n";
    }
    
    return 0;
}
