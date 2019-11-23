#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

int main(){
    // map
    std::map<std::string, unsigned> ordered{
            {"John", 1000},
            {"Tom", 1400},
            {"Harry", 800}
    };
    
    cout << "----- map -----" << "\n";
    auto bgn = ordered.begin(), end = ordered.end();
    for (auto iter = bgn; iter != end; ++iter) {
        cout << "Name: " << iter->first << ", Salary" << iter->second << "\n";
    }
    
    cout << "\n";
    
    // unordered_map
    std::unordered_map<std::string, unsigned> unordered{
            {"John", 1000},
            {"Tom", 1400},
            {"Harry", 800}
    };
    
    cout << "----- unordered_map -----" << "\n";
    auto bgn1 = unordered.begin(), end1 = unordered.end();
    for (auto iter2 = bgn1; iter2 != end1; ++iter2) {
        cout << "Name: " << iter2->first << ", Salary" << iter2->second << "\n";
    }
    
    
}
