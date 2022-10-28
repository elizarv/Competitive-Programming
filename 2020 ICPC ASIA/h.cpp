#include <bits/stdc++.h>
using namespace std;
void print() {cout<<endl;}
template<typename T,typename... E>
void print(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");print(e...);}
#define forn(i,x,n) for(int i=int(x);i<int(n);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
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
  
  int count(int u) { return sz[find(u)]; }
};

typedef pair<int, pii> edge; 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<edge> edges;
  forn(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.pb({w, {u, v}});
  }
  sort(edges.begin(), edges.end());

  int l = 0, r = m;
  while (l < r) {
    int mid = (l+r)/2;
    dsu ds(n);
    forn(i, mid, m) {
      edge &ed = edges[i];
      int u = ed.S.F, v = ed.S.S;
      ds.unite(u, v);
    }
    if (ds.size > 1) r = mid;
    else l = mid+1;
  }

  dsu ds(n);
  vector<edge> tree;
  forn(i, l-1, m) {
    edge &ed = edges[i];
    int u = ed.S.F, v = ed.S.S;
    if (ds.find(u) != ds.find(v)) {
      ds.unite(u, v);
      tree.pb(ed);
    }
  }
  reverse(tree.begin(), tree.end());

  ds = dsu(n);
  ll ans = 0;
  for (auto &ed : tree) {
    int u = ed.S.F, v = ed.S.S;
    ans += 1ll * ed.F * ds.count(u) * ds.count(v);
    ds.unite(u, v);
  }

  cout << ans << endl;
}


/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main h.cpp && ./main < h.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/