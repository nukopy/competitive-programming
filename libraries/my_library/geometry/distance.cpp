#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <bitset>
#include <sstream>
#include <cmath>
#include <climits>
#include <cctype>
#include <iomanip>
using namespace std;
using ll = long long;

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) :x(x),y(y){}
    Point operator+(Point p) {return Point(x+p.x,y+p.y);}
    Point operator-(Point p) {return Point(x-p.x,y-p.y);}
    Point operator*(double k){return Point(x*k,y*k);}
    Point operator/(double k){return Point(x/k,y/k);}
    double norm(){return x*x+y*y;}
    double abs(){return sqrt(norm());}

    bool operator < (const Point &p) const{
        return x!=p.x?x<p.x:y<p.y;
        //grid-point only
        //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    }
};

#define pll pair<ll, ll>
#define F first
#define S second

double dis(pll s, pll g) {
    return sqrt(pow(s.F - g.F, 2) + pow(s.S - g.S, 2));
}


int main() {
    
    return 0;
}