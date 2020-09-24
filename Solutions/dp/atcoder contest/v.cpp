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
int dp[N], ans[N], n, M;
vector<int> g[N];

int add(int a, int b){
  if(1ll*a + b >= M)return 1ll*a+b-M;
  return a+b;
}

int mult(int a, int b){
  if(1ll*a*b >= M)return (1ll*a*b) % M;
  return a*b;
}

int f(int u, int p){
    int &ans = dp[u];
    if(ans != -1)return ans;
    ans = 1;
    for(int v: g[u]){
        if(v == p)continue;
        int aux = add(f(v, u), 1);
        ans = mult(ans, aux);
    }
    return ans;
}

void reroot(int u, int p, int upch){
  dp[u] = mult(dp[u], add(upch, 1));
  int sz = g[u].size();
  vector<int> PRE(sz), SUF(sz);
  forn(i, 0, sz){
    int v = g[u][i];
    if(v != p)PRE[i] = dp[v];
    PRE[i] = add(PRE[i], 1);
    if(i) PRE[i] = mult(PRE[i-1], PRE[i]);
  }
  for(int i = sz-1; i >= 0; i--){
    int v = g[u][i];
    if(v != p)SUF[i] = dp[v];
    SUF[i] = add(SUF[i], 1);
    if(i+1 < sz)SUF[i] = mult(SUF[i+1], SUF[i]);
  }
  forn(i, 0, sz){
    int v = g[u][i];
    if(v == p)continue;
    int nxt = add(upch, 1);
    if(i)nxt = mult(nxt, PRE[i-1]);
    if(i+1 < sz) nxt = mult(nxt, SUF[i+1]);
    reroot(v, u, nxt);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int u, v;
  cin >> n >> M;

  forn(i, 0, n-1){
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  memset(dp, -1, sizeof dp);
  f(0, -1);
  reroot(0, -1, 0);

  forn(i, 0, n)cout << dp[i] << endl;

}



