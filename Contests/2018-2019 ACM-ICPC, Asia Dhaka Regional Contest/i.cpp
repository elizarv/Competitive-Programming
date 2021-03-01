#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

typedef double T;
struct p3 {
  T x, y, z;
  // Basic vector operations
  p3 operator + (p3 p) { return {x+p.x, y+p.y, z+p.z }; }
  p3 operator - (p3 p) { return {x - p.x, y - p.y, z - p.z}; }
  p3 operator * (T d) { return {x*d, y*d, z*d}; }
  p3 operator / (T d) { return {x / d, y / d, z / d}; } // only for floating point
  // Some comparators
  bool operator == (p3 p) { return tie(x, y, z) == tie(p.x, p.y, p.z); }
  bool operator != (p3 p) { return !operator == (p); }
};
p3 zero {0, 0, 0 };

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    vector<p3> p;
    int x, y, z;
    forn(i, 0, 3){
      cin >> x >> y >> z;
      p.pb({x, y, z});
    }
  }
  
}
