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

const int N = 1e5+5;
vector<int> g[N];
ll dp[N][2];
int mod = 1e9+7;
bool hasCh[N];



ll f(int u, int p, int col){
    ll &ans = dp[u][col];
    if(ans != -1)return ans;
    ans = 1;
    for(int v: g[u]){
        if(v == p)continue;
        ll aux = 0;
        if(!col)aux = f(v, u, col);
        aux = (aux+f(v, u, !col))%mod;
        ans = (ans*aux)%mod;
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, u, v;
  cin >> n;
  forn(i, 0, n-1){
      cin >> u >> v;
      u--,v--;
      g[u].pb(v);
      g[v].pb(u);
  }
  memset(dp, -1, sizeof dp);
  ll ans = f(0, -1, 0);
  ans = (ans + f(0, -1, 1))%mod;
  cout << ans << endl;


}



