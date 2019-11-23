#include <iostream>
#include <vector>
using namespace std;

//CUT HERE BEGIN ysys13
// めぐる式二分探索：バグりにくい
template <typename T>
T BinarySearch(vector<T> vec, T key) {
    // key: 検索対象の値
    T left = 0, right = (T)vec.size(), mid, idx_res;
    while (left < right) {
        mid = (left + right)/2;
        if (vec[mid] == key) {
            return mid;
        } else if (key < vec[mid]) {
            // 半分より下
            right = mid;
        } else if (vec[mid] < key) {
            // 半分より上
            // 必要ないが，分かりやすいように条件を記述してある．
            left = mid + 1;
        }
    }
}

//CUT HERE END

// 螺旋本の二分探索
// left = mid + 1 の実装がややこしい
template <typename T>
T rasen_BinarySearch(vector<T> vec, T key) {
    // key: 検索対象の値
    T left = 0, right = (T)vec.size(), mid, idx_res;
    while (left < right) {
        mid = (left + right)/2;
        if (vec[mid] == key) {
            return mid;
        } else if (key < vec[mid]) {
            // 半分より下
            right = mid;
        } else if (vec[mid] < key) {
            // 半分より上
            // 必要ないが，分かりやすいように条件を記述してある．
            left = mid + 1;
        }
    }
    return -1;
}

int printBinarySearch(vector<int> vec, int key) {
    int left = 0, right = (int)vec.size(), mid, idx_res, counter = 1;
    
    cout << "----- search start: key = " << key << " -----" << "\n";
    while (left < right) {
        mid = (left + right)/2;
        cout << counter << ": (left, mid, right) = (" << left << ", " << mid << ", " << right << ")" << "\n";
        
        if (vec[mid] == key) {
            cout << "Key: "<< key << " is found at idx: " << mid << "." << "\n";
            return mid;
        } else if (key < vec[mid]) {
            right = mid;
            cout << "range updated: right = " << right << "\n";
        } else if (vec[mid] < key) {
            left = mid + 1;
            cout << "range updated: left = " << left << "\n";
        }
        
        if (counter == 5) {
            cout << "Search is broken." << "\n";
            break;
        }
        
        counter++;
        cout << "\n";
    }
    
    cout << "Key: "<< key << " is NOT found." << "\n";
    return -1;
}

int test_printBS() {
    vector<int> vec = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> keys = {0, 1, 2, 4, 8, 15, 21, 22};
    
    for (int i = 0; i < keys.size(); ++i) {
        BinarySearch(vec, keys[i]);
        cout << "\n";
    }
    
    return 0;
}


int main() {
    
    return 0;
}
