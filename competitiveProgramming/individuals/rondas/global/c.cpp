#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9+1;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, x;
    cin >> n;
    vector<int> h(n);
    int mx = 0;
    forn(i, 0, n){
      cin >> x;
      h[i] = x;
      mx = max(mx, x);
    }
    int mn = inf;
    ll ans = 0;
    int frst = n;
    for(int i = n-1; i >= 0; i--){
      if(h[i] == mx){
        if(mx-mn > 0)ans += mx-mn;
        mn = inf;
        frst = i;
      }
      mn = min(mn, h[i]);
    }
    mx = 0; mn = inf;
    int cur = h[0];
    forn(i, 1, frst){
      while(i < frst && h[i] < cur){
        mn = min(mn, h[i]);
        i++;
      }
      if(mn != inf)ans += cur-mn;
      cur = h[i];
      mn = inf;
    }
    
    cout << ans << endl;

  }

    
  
}

