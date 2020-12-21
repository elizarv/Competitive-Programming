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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int mn = 1e9;
    vector<int> v;
    forn(i, 0, n){
      int x; cin >> x;
      v.pb(x);
      mn = min(mn, 100-x);
    }
    int ans = 0;
    for(auto x: v){
      if(x+mn >= 50)ans++;
    }
    cout << ans << endl;
  }
  
}
