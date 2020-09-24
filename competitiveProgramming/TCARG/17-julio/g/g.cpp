#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... arribargs>
void debug(T a,arribargs... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
vector<bool> spe(N);

struct dsu {
    vector<int> par, sz;
    int size;

    dsu(int n) {
        size = n;
    	par = sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i; sz[i] = 1;
        }
    }
    
    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    
    void unite(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return;
        if (spe[u]) swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    
    int count(int u) {
        return sz[find(u)];
    }
};



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m, k, u, v, w;
  vector<pair<int, pii> > edges;

  cin >> n >> m >> k;

  forn(i, 0, k){
      cin >> u;
      u--;
      spe[u] = true;
  }

  forn(i, 0, m){
      cin >> u >> v >> w;
      u--, v--;
      edges.pb({w, {u, v}});
  }

  sort(edges.begin(), edges.end());

  int ans = 0;

  dsu ds = dsu(n);

  for(auto x: edges){
      w = x.F;
      u = x.S.F;
      v = x.S.S;
      u = ds.find(u);
      v = ds.find(v);
      if(u != v){
          if(spe[u] && spe[v])ans = max(ans, w);
          ds.unite(u, v);
      }
  }

  forn(i, 0, k)cout << ans << " \n"[i+1 == k];






}

