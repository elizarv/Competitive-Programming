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

  int t; cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    bool f = false;
    pii ans = {1e9, 1e9};
    set<int> st;
    forn(i, 0, n){
      int x;
      cin >> x;
      if(x && k%x == 0 && st.count(k/x)){
        pii cur = minmax(x, k/x);
        ans = min(ans, cur);
        f = true;
      }
      st.insert(x);
    }
    if(f) cout << ans.F << " " << ans.S << endl;
    else cout << "-1" << endl;
    
  }
  
}

