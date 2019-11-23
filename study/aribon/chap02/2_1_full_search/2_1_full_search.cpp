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

// 再帰関数
ll factorial(ll n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

ll fibo(ll n) {
    // 0-origin
    if (n == 0 || n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

vector<ll> memo(1000, 0);
ll fibo_memo(ll n) {
    if (n == 0 || n == 1) return 1;
    if (memo[n] != 0) {
        // メモされているとき: そのままメモを返す
        return memo[n];
    } else {
        // メモされていないとき：メモしてから値を返す
        memo[n] = fibo_memo(n-1) + fibo_memo(n-2);
        cout << n << " : " << memo[n] << "\n";
        return memo[n];
    }
}

void test_factorial() {
    ll n = 5;
    cout << factorial(n) << "\n";
}

void test_fibo() {
    ll n = 5;
    //        i = 0, 1, 2, 3, 4, 5, ...
    // 0-origin: {1, 1, 2, 3, 5, 8, ...}
    cout << fibo(n) << "\n";
}

void test_fibo_memo() {
    ll n = 10;
    
    // メモの初期化
    memo[0] = 1;
    memo[1] = 1;
    
    cout << fibo_memo(n) << "\n";  // オーバーフローするけど fibo より高速に動く
}

void test_stack() {
    stack<ll> st;
    st.push(1);
    st.push(2);
    st.push(33);
    cout << "現在の一番上：" << st.top() << "\n";
    st.pop();
    cout << "現在の一番上：" << st.top() << "\n";
    st.pop();
    cout << "現在の一番上：" << st.top() << "\n";
    st.pop();
    
    // 空の状態
    // 空の状態で st.pop() を行うとセグフォが起こる
    // st.pop();
    // cout << "現在の一番上：" << st.top() << "\n";
}

void test_queue() {
    queue<ll> que;
    
    que.push(1);
    que.push(2);
    que.push(3);
    
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";
    que.pop();  // 1 を取り出す
    que.push(4);
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";
    cout << "後尾（最後に入れた数値）：" << que.back() << "\n";
    que.pop();  // 2 を取り出す
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";
    que.pop();  // 3 を取り出す
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";
    que.pop();  // 4 を取り出す
    
    // 空の状態
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";  // segmentation fault
    que.pop();  // 4 を取り出す
    cout << "先頭（先に入れた数値）：" << que.front() << "\n";  // segmentation fault
}

void test_basic() {
    // 再帰関数
    // factorial
    test_factorial();
    
    // fibo
    test_fibo();
    
    // fibo memo
    test_fibo_memo();
    
    // stack の練習
    test_stack();
    
    // queue の練習
    test_queue();
}

// 深さ優先探索
ll N, K;
vector<ll> vec;
bool dfs(ll res, ll depth) {
    if (res == K) return true;
    if (depth == N) return false;  // 一致しなかったら false
    
    return dfs(res + vec[depth], depth+1) || dfs(res, depth+1);
}

void bubunwa() {
    // 深さ優先探索
    // 蟻本 p.34
    // input
    cin >> N >> K;
    vec.resize(N);
    REP(i, N) cin >> vec[i];
    
    // calc
    ll init = 0;  // 和
    bool flag = dfs(init, 0);
    if (flag) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    
}

ll n, m, res = 0;
vector<vector<char>> field;
const ll dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const ll dy[] = {1, -1, 0, 1, -1, 0, 1, -1,};

void dfs_poj2386(ll x, ll y) {
    field[x][y] = '.';
    
    // 8 近傍の探索
    REP(i, 8) {
        ll next_x = x+dx[i], next_y = y+dy[i];
        if ((0 <= next_x && next_x < n) && (0 <= next_y && next_y < m)) {
            // まず，next_x と next_y が配列の範囲に収まるかチェックする
            if (field[next_x][next_y] == 'W') {
                dfs_poj2386(next_x, next_y);
            }
        }
    }
}

void POJ_2386() {
    // POJ_2386: Lake Counting
    // input
    cin >> n >> m;
    field = vector<vector<char>>(n, vector<char>(m));
    REP(i, n) REP(j, m) cin >> field[i][j];
    
    // calc
    REP(i, n) {
        REP(j, m) {
            if (field[i][j] == 'W') {
                dfs_poj2386(i, j);
                res++;
            }
        }
    }
    
    cout << res << "\n";
}



int main() {
    // 全探索の基本
    // test_basic();
    
    // 深さ優先探索
    // bubunwa();
    // POJ_2386();
    
    // 幅優先探索
    
    return 0;
}