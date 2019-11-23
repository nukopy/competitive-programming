// #include<bits/stdc++.h>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
using ll = long long;
//BEGIN CUT HERE ysys13
// エラトステネスの篩（Sieve of Eratosthenes）
// 0 〜 num までの素数を高速に求める

// ver0: normal
template <typename T>
vector<bool> eratosthenes0(T num) {
    std::vector<bool> flags(num, true);
    flags[0] = false;  // 0, 1 は素数でない
    flags[1] = false;  // 0, 1 は素数でない
    
    for (T i = 2; i*i < num; ++i) {
        if (!flags[i]) continue;  // flag[i] が false なら continue
        
        for (T mult = i*i; mult < num; mult += i) {
            flags[mult] = false;
        }
    }
    return flags;
}

// ver1: 2の倍数を省略
template <typename T>
vector<bool> eratosthenes1(T num) {
    // 注意：戻り値は 1 ~ n の奇数素数の flags: 1, 3, 5, 7, 9
    std::vector<bool> flags((num+1)/2, true);  // num = 31 のときは 16 個必要
    // flag[i] は 整数 2i + 1 を表す
    // flag[0] は 整数 2*0 + 1 = 1 の表す
    // flag[1] は 整数 2*1 + 1 = 3 のフラグを表す
    // flag[3] は 整数 2*3 + 1 = 7 のフラグを表す
    flags[0] = false;
    ll p, idx_start;
    for (T i = 1; i*i < num; ++i) {
        if (!flags[i]) continue;  // flag[i] が false なら continue
        
        p = 2*i + 1;  // flag[i] の整数
        idx_start = 2*i*(i+1);
        for (T mult = idx_start; mult < flags.size(); mult += p) {
            flags[mult] = false;
        }
    }
    return flags;
}

// 10^8 を篩に掛ける
// ver0 = 5000 ~ 6000 ms  // normal
// ver1 = 2000 ms  // 2の倍数を省略  // 2倍以上速くなった

// 1 ~ n までの素数の和
template <typename T>
ll primeSum(T num) {
    vector<bool> flags = eratosthenes1(num);
    ll sum = 0;
    if (num < 0) return -1;
    if (0 <= num && num <= 1) return 0;
    
    // 2
    sum += 2;  // ver1 では，2 は flags に入っていない
    for (int i = 0; i < flags.size(); ++i) {
        if (flags[i]) sum += 2 * i + 1;
    }
    return sum;
}
//END CUT HERE ysys13

int main() {
    vector<bool> flags;
    ll num = 100000000;  // 10^8
//    ll num = 100;
    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    start = std::chrono::system_clock::now(); // 計測開始時間
    flags = eratosthenes1(num);
    end = std::chrono::system_clock::now();  // 計測終了時間
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    
    bool debug = true;
    if (debug) {
        // ver0
//        for (int i = 0; i < num; ++i) {
//            if (flags[i]) cout << i << "\n";
//        }
        // ver2 1 ~ n までの素数の和
        ll sum = primeSum(5);
        cout << sum << "\n";
    }
    cout << "time: " << elapsed << " ms"  << "\n";
    return 0;
}
