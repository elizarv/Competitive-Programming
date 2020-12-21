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
    int n, s;
    cin >> n >> s;
    vector<int> coins;
    forn(i, 0, n){
      int x;
      cin >> x;
      coins.pb(x);
    }
    int ans = 0;
    forn(mask, 1, (1 << n)){
      int sum = 0, cnt = 0;
      int mn = 1e9;
      forn(i, 0, n){
        if(mask >> i & 1){
          cnt++;
          sum += coins[i];
          mn = min(mn, coins[i]);
        }
      }
      if(sum < s)continue;
      if(sum - mn < s)ans = max(ans, cnt);
    }
    cout << ans << endl;
  }
  
}

