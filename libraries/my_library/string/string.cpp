#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

/*
辞書順
a < b < c
abc < abcd
abbbb < abbbbb
aaa < aaaa
*/

/*
部分文字列
S.substr(0, i)
S.substr(i)

例えば，26 文字あった時，上から 3 文字で分断する時
前半 = S.substr(0, 26-3);  0 から 23 文字
後半 = S.substr(26-3);  idx = 23 以降の文字: 23, 24, 25
*/

/*
 * 文字列検索・置換
 ・find(検索文字列, 検索開始位置=0): str.find("hoge", start_idx)
 
 指定された検索文字列を、指定位置から末尾に向かって検索し、
 マッチした場合はその位置を返す（型は size_t）。
 開始位置を省略した場合は、先頭から検索する。
 検索文字列が無かった場合は size_t の最大値を返す（ -1 に相当する値）。
 size_t の最大値は、int型にキャストすると -1 になる。
 
 ・rfind(検索文字列, 検索開始位置=文字列長): str.rfind("hoge", start_idx)
 
 reverse_find
 指定された検索文字列を、指定位置から先頭に向かって検索し、
 マッチした場合はその位置を返す（型は size_t）。
 開始位置を省略した場合は、「末尾」から検索する。
 検索文字列が無かった場合は size_t の最大値を返す（ -1 に相当する値）。
 見つからないときは，int にキャストして -1 を返す．
 
 ・replace(位置, 置換文字数, 置換文字列)
 
 指定位置から指定文字数を置換文字列で置き換える。
 置換文字数は異なっても良いが，計算量には注意が必要．
 

*/

int test_find_rfind() {
    // str.find("hoge", idx_start)
    string str = "abcabc";
    
    cout << "----- test str.find -----" << "\n";
    cout << (int)str.find("b") << "\n";  //  マッチする場合
    cout << (int)str.find("b", 3) << "\n";  //  ３文字目から末尾に向かって検索
    cout << (int)str.find("bc") << "\n";  //  ３文字目から「末尾」に向かって検索
    cout << (int)str.find("bc", 3) << "\n";  //  ３文字目から末尾に向かって検索
    cout << (int)str.find("x") << "\n";  // int にキャストして -1 になる
    cout << "\n";
    
    cout << "----- test str.rfind() -----" << "\n";
    std::string str1 = "abcabc";
    std::cout << (int)str1.rfind("b") << "\n";    //  マッチする場合
    std::cout << (int)str1.rfind("b", 3) << "\n";    //  ３文字目から「先頭」に向かって検索
    cout << (int)str1.rfind("bc") << "\n";  //  ３文字目から末尾に向かって検索
    cout << (int)str1.rfind("bc", 3) << "\n";  //  ３文字目から末尾に向かって検索
    std::cout << (int)str1.rfind("x") << "\n";    //  マッチしない場合
    cout << "\n";
    
    return 0;
}

int test_replace() {
    // 下記は、"12345" の 2文字目から2文字を "xyz" に置き換える例。
    string str = "12345";
    
    cout << "----- test str.replace() -----" << "\n";
    cout << str << "\n";
    str.replace(1, 2, "xyz");  // str[1] から 2文字を "xyz" 3文字に置換
    cout << str << "\n";
    cout << "\n";
}

// BEGIN CUT
// 文字列中の特定の1文字を別の1文字に置換：O(N)
void replaceStr(string &str, char target, char sub) {
    // target -> sub
    for (ll i = 0; i < str.length(); ++i) {
        if (str[i] == target) {
            str[i] = sub;
        }
    }
}
// END CUT

// verified
int test_replaceStr() {
    // 文字列中の 'n' を 'X' に置換
    string str = "aanabbndfdfnffnndlnjjfjwpjlsanfkhsdjfhgvnnzxvsdngnh";
    char target = 'n', sub = 'X';
    
    cout << "----- test replaceStr() -----" << "\n";
    cout << str << "\n";
    replaceStr(str, target, sub);
    cout << str << "\n";
    cout << "\n";
    
    //>>> aanabbndfdfnffnndlnjjfjwpjlsanfkhsdjfhgvnnzxvsdngnh
    //>>> aaXabbXdfdfXffXXdlXjjfjwpjlsaXfkhsdjfhgvXXzxvsdXgXh
    
    return 0;
}

int main() {
    test_find_rfind();
    test_replace();
    test_replaceStr();
    
    return 0;
}
