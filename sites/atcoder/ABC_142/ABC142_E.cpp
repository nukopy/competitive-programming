// ABC142_E
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
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M;
    cin >> N >> M;
    
    // calculation
    vector<ll> takara(N+1, INF);
    vector<ll> vec_key_num(N+1, -1);  // 各宝箱を開けるための鍵番号
    vector<ll> num(N+1, 0);  // 各鍵が使われている数
    
    REP(i, M) {
        ll a_i, b_i;
        cin >> a_i >> b_i;  // a: 円, b: b種類の宝箱
        vector<ll> vec(b_i);
        ll num_key = 0;
        
        REP(i, b_i) {
            ll num_takara, key_number = i+1;
            cin >> num_takara;
            
            // 小さい方を買うよりも二つセットの鍵を買った方が良い
            if(takara[num_takara] > a_i) {
                if (vec_key_num[num_takara] == -1) {
                    // 初出
                    takara[num_takara] = a_i;
                    vec_key_num[num_takara] = key_number;
                    num_key++;
                } else {
                    // すでに鍵が存在する時，変更前後のコストを計算する
                    ll before = takara[num_takara];
                    ll after = takara[num_takara] * (num[key_number]-1) + a_i;
                    if (after < before) {
                        takara[num_takara] = a_i;
                        vec_key_num[num_takara] = key_number;
                        num_key++;
                    }
                }
            }
            num[key_number] = num_key;
        }
    }
    
    for (ll i = 1; i < takara.size(); ++i) {
        if (takara[i] == INF) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    takara[0] = 0;
    cout << SUM(takara) << "\n";
    
    return 0;
}