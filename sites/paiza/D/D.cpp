#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
    // FizzBuzz
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        if (i % 15 == 0) {
            cout << "FizzBuzz" << "\n";
        } else if (i % 3 == 0) {
            cout << "Fizz" << "\n";
        } else if (i % 5 == 0) {
            cout << "Buzz" << "\n";
        } else {
            cout << i << "\n";
            sum += i;
        }
    }
    cout << sum << "\n";
    return 0;
}