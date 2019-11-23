// ABC006_C
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    // input
    int human, foot;
    cin >> human >> foot;
    
    // calculation
    if (foot < human * 2 || human * 4 < foot) {
        // (human, foot) = (2, 3) は足が足りない(3 < 2 * 2)
        // (human, foot) = (1, 5) は人が足りない(1 * 4 < 5)
        // 最低必要な人数，最大可能な人数で絞り込む
        cout << -1 << " " << -1 << " " << -1 << "\n";
    } else if (human == 1) {
        if (foot == 2) {
            cout << 1 << " " << 0 << " " << 0 << "\n";
        } else if (foot == 3) {
            cout << 0 << " " << 1 << " " << 0 << "\n";
        } else if (foot == 4) {
            cout << 0 << " " << 0 << " " << 1 << "\n";
        } else {
            cout << -1 << " " << -1 << " " << -1 << "\n";
        }
    } else {
        // 人が二人以上
        int adult = max(0, 3*human - foot);
        int roujin = min(foot - 2*human, 4*human - foot);
        int baby = max(0, foot - 3*human);
        cout << adult << " " << roujin << " " << baby << "\n";
    }
    return 0;
}
