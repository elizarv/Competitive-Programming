#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n, m, l, k, d[N];
vector<pii> g[N];

void bfs (int u) {
  queue<int> q;
  q.push(u);
  d[u] = 0;
  while (SZ(q)) {
    u = q.front();
    q.pop();
    for (pii v: g[u]) {
      if (d[v.F] == -1) {
        d[v.F] = d[u] + 1;
        q.push(v.F);
      }
    }
  }
}

void init () {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    d[i] = -1;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("path.in", "r" , stdin);
  
  int t, ans, u;
  cin >> t;
  while (t--) {
    cin >> n >> m >> u >> l >> k;
    u--;
    init();
    for (int i = 0, x, y, w; i < m; i++) {
      cin >> x >> y >> w;
      x--, y--;
      g[x].pb({y, w});
      g[y].pb({x, w});
    }
    bfs(u);
    ans = 0;
    for (u = 0; u < n; u++) {
      if (d[u] >= k) continue;
      for (pii v: g[u]) {
        ans = max(ans, v.S);
      }
    }
    cout << ans << endl;
  }
}