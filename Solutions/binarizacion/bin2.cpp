//https://codeforces.com/gym/102222/problem/G
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... E>
void debug(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");debug(e...);}
#define forn(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5, M = 105;
const ll inf = 1e18;
vector<pii> g[N];
ll dp[N][M], temp[M];
int sz[N];
int k;

void reset_temp(int n){
  forn(i, 0, min(n, k) + 1){
    temp[i] = inf;
  }
}

void dfs(int u, int p){
  dp[u][0] = 0;
  if(g[u].size() == 1){
    dp[u][1] = 0;
    sz[u] = 1;
  }
  for(auto &nx: g[u]){
    int v = nx.F;
    if(v == p)continue;
    dfs(v, u);
    int w = nx.S;
    reset_temp(sz[u] + sz[v]);
    forn(x, 0, min(sz[u], k) + 1){
      forn(y, 0, min(sz[v], k - x) + 1){
        temp[x + y] = min(temp[x + y], dp[u][x] + dp[v][y] + 1ll * y * (k - y) * w);
      }
    }
    sz[u] += sz[v];
    forn(x, 0, min(sz[u], k) + 1){
      dp[u][x] = temp[x];
    }
  }
}

void init(int n){
  forn(i, 0, n){
    g[i].clear();
    sz[i] = 0;
    forn(j, 0, k + 1){
      dp[i][j] = inf;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);       

  int t, caso = 1;
  cin >> t;
  while(t--){
    cout << "Case #" << caso++ << ": ";
    int n;
    cin >> n >> k;
    init(n);
    forn(i, 0, n - 1){
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g[u].pb({v, w});
      g[v].pb({u, w});
    }

    dfs(0, 0);

    ll ans = inf;
    forn(u, 0, n){
      ans = min(ans, dp[u][k]);
    }

    cout << ans << endl;

  }

}