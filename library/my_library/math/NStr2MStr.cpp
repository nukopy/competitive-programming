#include<string>
#include<iostream>

/*
2, 8, 10, 16 進数以外を相互に変換する．
コンストラクタに引数を与えれば 17 進数以上も相互に変換できる．
ref. to https://qiita.com/hakomo/items/fd7212d71269cea311e5
*/
class Radix {
private:
    const char* s;
    int a[128];
public:
    // コンストラクタ
    Radix(const char* s = "0123456789ABCDEF") : s(s) {
        int i;
        for(i = 0; s[i]; ++i)
        a[(int)s[i]] = i;
    }
    
    // メンバ関数
    // 関数のオーバーロード：引数が数値，文字列で昨日が異なる
    std::string to(long long p, int q) {
        // 10進数 -> q 進数文字列 の変換
        // args: p(long long), q(int)
        // ret: q 進数文字列 (string)
        int i;
        if(!p) return "0";
        char t[64] = { };
        for(i = 62; p; --i) {
            t[i] = s[p % q];
            p /= q;
        }
        
        return std::string(t + i + 1);
    }
    
    std::string to(const std::string& t, int p, int q) {
        // p進数文字列 -> q進数文字列 の変換
        // args: t(string), p(int), q(int)
        // ret: q 進数文字列 (string)
        return to(to(t, p), q);
    }
    
    long long to(const std::string& t, int p) {
        // p進数文字列(string) -> 10進数(long long) の変換
        // args: p(long long), q(int)
        // ret: q 進数文字列 string
        int i;
        long long sm = a[(int)t[0]];
        for(i = 1; i < (int)t.length(); ++i)
        sm = sm * p + a[(int)t[i]];
        return sm;
    }
};

int main() {
    Radix r;
    // 10 進数を n 進文字列に
    std::cout << r.to(255, 10) << std::endl; // => "255"
    std::cout << r.to(255, 12) << std::endl; // => "193"
    std::cout << r.to(255, 16) << std::endl; // => "FF"

    // n 進文字列を m 進文字列に
    std::cout << r.to("255", 7, 11) << std::endl; // => "116"
    std::cout << r.to("255", 11, 7) << std::endl; // => "611"
    
    // n 進文字列を 10 進数に
    std::cout << r.to("255", 10) << std::endl; // => 255
    std::cout << r.to("255", 14) << std::endl; // => 467
    
    // 10 進数を -2 進文字列に
    std::cout << r.to(123456789, -2) << std::endl; // => "255"

    return 0;
}
