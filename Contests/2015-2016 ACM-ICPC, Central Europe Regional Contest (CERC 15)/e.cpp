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

typedef pair<int, pii> edge;
const int N = 3e5+5;
int deg[N], deg0, deg2;

struct dsu{
    vector<int> par, sz, deg2;
    int n, cycles;

    dsu(int sz): par(sz), sz(sz, 1), deg2(sz) {
        n = sz;
        cycles = 0;
        iota(par.begin(), par.end(), 0);
    }
    int find(int u){
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v)return;
        if(sz[v] > sz[u])swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        deg2[u] += deg2[v];
        n--;
    }
    void update(int u, int x){
        u = find(u);
        if(x == 2){
            deg2[u]++;
            if(sz[u] == deg2[u])cycles++;
        }
        if(x == 3){
            if(sz[u] == deg2[u])cycles--;
            deg2[u]--;
        }
    }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<edge> ed(m);

  forn(i, 0, m){
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;
      ed[i] = {c, {u, v}};
  }
  sort(ed.rbegin(), ed.rend());

  int q; cin >> q;
  vector<pii> query(q);
  forn(i, 0, q){
      int x;
      cin >> x;
      query[i] = {x, i};
  }
  sort(query.rbegin(), query.rend());

  vector<pii> ans(q);

  int nodes = 1;
  int edges = 0;

  int i = 0;
  dsu dsu(n);
  deg0 = n, deg2 = 0;

  for(auto &x: query){
      while(i < m && ed[i].F >= x.F){
          int u = ed[i].S.F;
          int v = ed[i].S.S;
          if(!deg[u])deg0--;
          if(!deg[v])deg0--;
          deg[u]++;
          deg[v]++;
          if(deg[u] == 2){
              deg2++;
              dsu.update(u, deg[u]);
          }
          if(deg[v] == 2){
              deg2++;
              dsu.update(v, deg[v]);
          }
          if(deg[u] == 3){
              deg2--;
              dsu.update(u, deg[u]);
          }
          if(deg[v] == 3){
              deg2--;
              dsu.update(v, deg[v]);
          }
          dsu.unite(u, v);
          i++;
      }
      nodes = n-deg2-deg0+dsu.cycles;
      edges = i-deg2+dsu.cycles;
      ans[x.S] = {nodes, edges};
  }

  for(auto &x: ans){
      cout << x.F << " " << x.S << endl;
  }



  
}
