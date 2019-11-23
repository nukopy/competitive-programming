// ABC114_C
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll N, res = 0;

void dfs(ll x, bool f3, bool f5, bool f7) {
    if (x <= N) {
        if (f3 && f5 && f7) res++;
        dfs(10*x + 3, true, f5, f7);
        dfs(10*x + 5, f3, true, f7);
        dfs(10*x + 7, f3, f5, true);
    }
}

int main() {
    // input
    cin >> N;
    
    // calculation
    dfs(0, false, false, false);
    cout << res << "\n";
    
    return 0;
}
