// ABC007_C
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i=0; i < n; i++)  // 0 ~ n-1

struct Plane {
    ll first;
    ll second;
    ll third;
};

ll N, M, s_y, s_x, g_y, g_x, y, x, depth;
vector<string> vec;
vector<ll> y_vec = {0, 0, -1, +1}, x_vec = {-1, +1, 0, 0};  // 進む方向の簡便化
queue<Plane> q;

ll bfs() {
    while (!q.empty()) {
        Plane now = q.front();
        q.pop();
        y = now.first, x = now.second, depth = now.third;
        if (y == g_y && x == g_x) return depth;
        
        depth++;  // 深さを一つ深くする
        
        // 進むを enqueue
        for (ll i = 0; i < 4; ++i) {
            Plane next = {y + y_vec[i], x + x_vec[i], depth};
            if (0 <= next.first && next.first <= N-1 && 0 <= next.second && next.second <= M-1 && vec[next.first][next.second] == '.') {
                vec[next.first][next.second] = 'x';
                q.push(next);
            }
        }
    }
    
    return 0;
}

int main() {
    // input
    cin >> N >> M >> s_y >> s_x >> g_y >> g_x;
    s_y--, s_x--, g_y--, g_x--;
    
    vec.resize(N);
    REP(i, N) cin >> vec[i];
    
    // calculation
    Plane start = {s_y, s_x, 0};
    q.emplace(start);
    
    cout << bfs() << "\n";
    
    return 0;
}
