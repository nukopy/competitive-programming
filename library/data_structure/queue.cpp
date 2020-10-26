#include <iostream>
#include <queue>
#include <string>
#include <utility>  // std::pair
using namespace std;
using ll = long long;

/* キュー（待ち行列）の基礎：他のコンテナ型と同じ部分がある
queue.back()  -----------   queue.front()
queue.push()->   queue   -> queue.pop()
(enqueue)     -----------  (dequeue)

 * First In First Out: FIFO
・次に pop で取り出される（一番初めにキューに挿入された要素）：queue.front()
・要素を（一番後ろに）入れる：queue.push(num)
・要素を取り出す．：queue.pop(num)：戻り値は void
・直接構築でキューに要素を追加：stack.emplace()
stack.(), stack
*/

int test_queue() {
    // test queue.push()
    cout << "----- test queue.push() -----" << "\n";
    queue<int> que1;
    que1.push(3);
    que1.push(1);
    que1.emplace(4);
    
    while (!que1.empty()) {
        // queue.front() 次に dequeue で取り出される要素
        cout << que1.front() << "\n";
        que1.pop();
    }
    // test queue.emplace()
    cout << "----- test queue.emplace() -----" << "\n";
    queue<pair<int, string>> que2;
    que2.emplace(3, "aaa");
    que2.emplace(1, "bbb");
    que2.emplace(4, "ccc");
    
    while (!que2.empty()) {
        // queue.front() 次に dequeue で取り出される要素
        cout << que2.front().first << " " << que2.front().second << "\n";
        que2.pop();
    }
    return 0;
}

// verified AOJ: ALDS1_3_B
int ALDS1_3_B() {
    // input
    int n, q;
    cin >> n >> q;
    int t;
    string process;
    queue< pair<string, int> > que;
    for (ll i = 0; i < n; ++i) {
        cin >> process >> t;
        que.emplace(process, t);
    }
    
    // calculation
    int time = 0;
    pair<string, int> tmp;
    while (!que.empty()) {
        tmp = que.front();
        que.pop();
        if (tmp.second > q) {
            tmp.second -= q;
            time += q;
            que.push(tmp);
        } else {
            time += tmp.second;
            cout << tmp.first << " " << time << "\n";
        }
    }
    
    return 0;
}

int main() {
    // test_queue();
    ALDS1_3_B();
    
    return 0;
}
