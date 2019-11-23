#include <iostream>
using namespace std;

// 階乗と組み合わせ計算：MOD 考慮版
// 
// CUT HERE BEGIN
template <typename T>
T factorial(T num) {
    if (num == 0 || num == 1) {
        // 0! = 1, 1! = 1;
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}
template <typename T>
T nCr(T n, T r) {
    return factorial(n)/(factorial(r)*factorial(n-r));
}
// CUT HERE END

int test() {
    int num = 6;
    int n = 10, r = 3;
    cout << num << "! = " << factorial(num) << "\n";
    cout << n << " C " << r << " = " << nCr(n, r) << "\n";
    // 6! = 720
    // 10 C 3 = 120
    return 0;
}

int main() {
    test();
    return 0;
}
