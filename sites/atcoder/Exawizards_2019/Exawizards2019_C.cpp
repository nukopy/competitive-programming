// Exawizards2019_C
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
// #define F first
// #define S second
const ll INF = 1LL<<60;  // 10^18（const int inf   = 1<<29;）

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, Q;
	cin >> N >> Q;
    string S;
	cin >> S;
	vector<ll> Alpha(N);
	REP(i, N) {
		Alpha[i] = S[i] - 'A';  // 文字を数値（0-25）に変換
	}
	
	// preparation
	vector<ll> Golem(N, 1), Query(Q), Direct(Q);  // 全てのマスにゴーレムがいる状態;
	char t_i, d_i; ll t;
	REP(i, Q) {
		cin >> t_i >> d_i;
		t = t_i - 'A';
		Query[i] = t;
		Direct[i] = (d_i == 'L' ? -1: +1);  // left: -1, right: +1
	}
	
	// calculation
	ll que, dir, now_G, res = N;
	REP(i, Q) {
		que = Query[i], dir = Direct[i];
		
	}
    
	cout << SUM(Golem) << "\n";
	
    return 0;
}