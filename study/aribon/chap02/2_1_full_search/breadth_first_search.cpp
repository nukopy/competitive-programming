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

struct Plane {
    ll x, y;
};

const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, -1, 1};

template <class T>
void print2DVec(vector<vector<T>> &vec) {
    size_t len = vec.size(), front = vec.front().size();
    REP(i, len) {
        REP(j, front) {
            if (j) cout << " ";
            cout << vec[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll N, M;
    cin >> N >> M;
    Plane start, goal;
    cin >> start.x >> start.y; start.x--, start.y--;
    cin >> goal.x >> goal.y; goal.x--, goal.y--;
    
    vector<vector<char>> map(N, vector<char>(M));
    REP(i, N) REP(j, M) cin >> map[i][j];
    
    // calculation
    vector<vector<ll>> count(N, vector<ll>(M, 0));
    count[start.x][start.y] = 0;
    queue<Plane> que;
    que.push(start);  // 初期位置
    
    while(!que.empty()) {
        // 現在地を取り出す
        Plane now = que.front(); que.pop();
        map[now.x][now.y] = '#';
        
        // 上下左右に進む
        REP(i, 4) {
            // n_x: next_x
            Plane next;
            next.x = now.x + dx[i], next.y = now.y + dy[i];
            if ((0 <= next.x && next.x < N) && (0 <= next.y && next.y < M) && map[next.x][next.y] == '.') {
                map[next.x][next.y] = '#';
                count[next.x][next.y] = count[now.x][now.y] + 1;
                que.push(next);
            }
        }
        print2DVec(count);
    }
    
    cout << count[goal.x][goal.y] << "\n";
    
    return 0;
}