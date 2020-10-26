#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//BEGIN CUT HERE
template <typename T>
T isPrime(T x){
    if(x <= 1) {
        // 0，1は素数じゃない
        return 0;
    } else if (x == 2) {
        // 2は素数
        return 1;
    } else if (x%2 == 0) {
        // 偶数は除く
        return 0;
    } else {
        // 偶数は２で割り切れるため除く
        for(T i = 3; i*i <= x; i+=2) {
            if(x%i == 0) return 0;
        }
        return 1;
    }
}
//END CUT HERE

// verified AOJ: ALDS1_1_C
int main() {
    ll N, num, sum = 0;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> num;
        sum += isPrime(num);
    }
    
    cout << sum << "\n";
    
    return 0;
}
