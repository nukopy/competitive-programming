// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

//BEGIN CUT HERE ysys13
// 各桁の総和：813 -> 12
template <class T>
T digitSum(T num) {
    
    ll sum = 0;
    while (num != 0) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}

// 桁数を数える：813 -> 3
template <class T>
T getDigit(T num) {
    if (num == 0) return 1;
    
    ll digits = 0;
    while (num != 0) {
        digits++;
        num /= 10;
    }
    return digits;
}
//END CUT HERE ysys13


int main() {
    ll num;
    cin >> num;
    
    vector< pair<ll, ll> > vec = primeFactorization(num);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i].first << "^" << vec[i].second << "\n";
    }
    return 0;
}
