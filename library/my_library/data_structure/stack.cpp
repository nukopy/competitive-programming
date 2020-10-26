#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;

/* スタックの基礎：他のコンテナ型と同じ部分がある
 * Last In First Out: LIFO の原則
・要素を入れる．：stack.push(num)
・要素を取り出す．：stack.pop(num)(pop_back も同じ)：戻り値は void
・頂点の要素を返す：stack.top(num)：戻り値は頂点の num
・直接構築でスタックに要素を追加：stack.emplace_back()
stack.(), stack
*/

int stack_test() {
    stack<int> stk;
    
    // how to use stack
    cout << stk.size() << "\n";
    
    stk.push(3);
    stk.push(7);
    stk.push(1);
    
    cout << stk.size() << "\n";
    cout << stk.top() << "\n";
    // cout << stk.pop() << "\n"; pop(), pop_back() は戻り値がない
    
    stk.push(5);
    stk.push(100);
    stk.push(87);
    
    // 空になるまで取り出す
    while (!stk.empty()) {
        cout << stk.top() << "\n";
        stk.pop();
    }
    
}

// verified AOJ: ALDS1_3_A
int ALDS1_3_A() {
    string ope;
    stack<long> stk;
    // 1 2 + 3 4 - *
    // (1+2)*(3-4)
    long a, b;
    while (cin >> ope) {
        if (ope[0] == '+') {
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b + a);  // 順序に注意
        } else if (ope[0] == '-') {
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b - a);  // 順序に注意
        } else if (ope[0] == '*'){
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b * a);
        } else {
            // std::stoi stringをintに変換
            stk.push(stoi(ope));
        }
    }
    
    cout << stk.top() << "\n";
    
    return 0;
}

int main() {
    // stack_test();
    ALDS1_3_A();
    return 0;
}
