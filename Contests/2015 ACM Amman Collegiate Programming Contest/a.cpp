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

struct person {
  string name;
  int s, p;

  bool operator < (const person& x) const {
    if(s == x.s)return p < x.p;
    return s > x.s;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<person> v;
    forn(i, 0, n){
      string name;
      int s, p;
      cin >> name >> s >> p;
      v.pb({name, s, p});
    }
    sort(v.begin(), v.end());
    cout << v[0].name << endl;
  }
  
}
