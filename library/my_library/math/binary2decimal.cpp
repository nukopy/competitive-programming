#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

//CUT HERE BEGIN ysys13
// 2 進数文字列(std::string)から 10 進数(long long)へ変換
ll BinaryStr2Decimal(string &S) {
    // 10^18(long long) 程度にしか使えないので注意
    // オーバーフローに注意
    if (S == "0" || S == "1") return stoll(S);
    ll res = 0, len = S.length()-1;
    for (ll i = len; i >= 0; --i) {
        res += (S[i] == '1')? (ll)pow(2, len-i): 0;  // 2^n 指数に注意
    }
    
    return res;
}
//CUT HERE END

//CUT HERE BEGIN ysys13
// 10 進数(long long)から 2 進数文字列(std::string)へ変換
string Decimal2BinaryStr(ll n) {
    // 10^18(long long) 程度にしか使えないので注意
    if (n == 0 || n == 1) return to_string(n);
    ll res = 0, cnt = 0;
    while (n != 0) {
        res += (n%2)*(ll)pow(10, cnt);  // 10進数で数字をつくる
        n /= 2;
        cnt++;
    }
    return to_string(res);
}
//CUT HERE END

//CUT HERE BEGIN ysys13
// N 進数文字列(std::string)から M 進数文字列(std::string)へ変換
void NStr2MStr(string S) {
    // 別のファイルへ
}
//CUT HERE END

int test_Binary2Decimal() {
    string s1 = "1101", s2 = "111", s3 = "0111", s4 = "110001010110011011";
    
    cout << "string --> BinaryStr2Decimal --> Decimal2BinaryStr" << "\n";
    cout << s1 << " --> " << BinaryStr2Decimal(s1) << " --> " << Decimal2BinaryStr(BinaryStr2Decimal(s1)) << "\n";
    cout << s2 << " --> " << BinaryStr2Decimal(s2) << " --> " << Decimal2BinaryStr(BinaryStr2Decimal(s2)) << "\n";
    cout << s3 << " --> " << BinaryStr2Decimal(s3) << " --> " << Decimal2BinaryStr(BinaryStr2Decimal(s3)) << "\n";
    cout << s4 << " --> " << BinaryStr2Decimal(s4) << " --> " << Decimal2BinaryStr(BinaryStr2Decimal(s4)) << "\n";
    
    return 0;
}

int main() {
    test_Binary2Decimal();
    return 0;
}

