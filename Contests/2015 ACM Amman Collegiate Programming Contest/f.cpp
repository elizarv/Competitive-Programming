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

struct dsu {
    vector<int> par, sz;
    int size; 

    dsu(int n) : par(n), sz(n, 1) {
        size = n;
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }

};

struct edge {
  int u, v, w;

   bool operator < (const edge& x) const {
     return w < x.w;
   }
};

vector<edge> g;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    g.clear();
    forn(i, 0, m){
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g.pb({u, v, w});
    }
    sort(g.begin(), g.end());
    dsu dsu(n);
    int ans = 0;
    for(auto ed: g){
      dsu.unite(ed.u, ed.v);
      if(dsu.size == 1){
        ans = ed.w;
        break;
      }
    }
    cout << ans << endl;
  }
  
}
