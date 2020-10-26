// #include<bits/stdc++.h>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

//BEGIN CUT HERE ysys13
template <typename T>
vector< pair<T, T> >  primeFactorization(T n) {
    // 因数分解
    vector< pair<T, T> > vec;
    
    // calculation
    if (0 <= n && n <= 3) {
        // 0 ~ 3 はそのまま
        vec.emplace_back(n, 1);
        return vec;
    } else {
        if (n < 0) n *= -1;  // 負の時は -1 掛けてから
        T counter;
        // 素因数 2 を先に処理
        if (n%2 == 0) {
            counter = 0;
            while (n%2 == 0) {
                n/=2;
                counter++;
            }
            if (counter != 0) {
                vec.emplace_back(2, counter);
            }
        }
        // 3, 5, 7, ... を処理
        for (int i = 3; i*i <= n; i += 2) {
            counter = 0;
            // i が因数のときの指数を求める
            while (n%i == 0) {
                n /= i;
                counter++;
            }
            // 素因数の指数のペアを vec へ入れる
            if (counter != 0) {
                vec.emplace_back(i, counter);
            }
        }
        
        // 残った素数（必ず素数になっている）を入れる
        if (n != 1) {
            vec.emplace_back(n, 1);
        }
        
        return vec;
    }
}
//END CUT HERE ysys13

//CUT HERE BEGIN ysys13
template <typename T>
vector<T> divisor(T n) {
    // 約数列挙(n 自身は含まない，必要に応じて vec.push_back())
    vector<T> vec;
    for(T i = 1; i*i <= n ; ++i) {
        if (n%i == 0) {
            vec.push_back(i);
            if (i != 1 && i*i != n) {
                vec.push_back(n / i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    return vec;
}
//CUT HERE END

//BEGIN CUT HERE beet
template<typename T>
map<T, T> factorize(T x){
    map<T, T> res;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            res[i]++;
        }
    }
    if(x!=1) res[x]++;
    return res;
}
//END CUT HERE

int main() {
    ll num;
    cin >> num;
    
    vector< pair<ll, ll> > vec = primeFactorization(num);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].first << "^" << vec[i].second << "\n";
    }
    return 0;
}
