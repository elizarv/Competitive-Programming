#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct edge { int v, w; };

const int MX = 2e5+5;
const int LG = 30;
vector<edge> g[MX];
vector<int> dep; 
int par[LG][MX];
int rmq[LG][MX]; 
int n, m; 

void pre(int u, int p, int d) {
    dep[u] = d;
    par[0][u] = p;
    for (auto &ed : g[u]) {
        int v = ed.v;
        if (v != p) {
            rmq[0][v] = ed.w;
            pre(v, u, d + 1);
        }
    }
}

void build() {
    dep.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (dep[i] == -1) {
            rmq[0][i] = -1;
            pre(i, i, 0);
        }
    }
    for (int j = 0; j < LG-1; j++) {
        for (int i = 0; i < n; i++) {
            par[j+1][i] = par[j][ par[j][i] ];
            rmq[j+1][i] = max(rmq[j][ par[j][i] ], rmq[j][i]);
        }
    }
}

int lca(int u, int v) {
    int ans = -1;
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = LG-1; i >= 0; i--) {
        if (dif & (1<<i)) {
            ans = max(ans, rmq[i][u]);
            u = par[i][u];
        }
    }
    if (u == v) return ans;
    for (int i = LG-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            ans = max({ans, rmq[i][u], rmq[i][v]});
            u = par[i][u];
            v = par[i][v];
        }
    }
    return max({ans, rmq[0][u], rmq[0][v]});
}

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
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return true;
        if (sz[u] > sz[v]) swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
        return false;
    }

		bool same(int u, int v){
			u = find(u), v = find(v);
			return u == v;
		}
};

struct query{
    int u, v, t;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int q;
  cin >> n >> q;

  vector<query> Q;
  dsu dsu(n);

  forn(i, 1, q+1){
      int t, u, v;
      cin >> t >> u >> v;
      u--, v--;
      if(t == 1){
          if(!dsu.unite(u, v)){
              g[u].pb({v, i});
              g[v].pb({u, i});
          }
      }else{
          Q.pb({u, v, i});
      }
    }

		build();

    for(auto &x: Q){
        int mn = lca(x.u, x.v);
				if(x.u == x.v)cout << "0";
				else if(!dsu.same(x.u, x.v) || mn > x.t || mn == -1)cout << ":(";
				else cout << mn;
				cout << endl;
    }
}