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

const int MX = 2e5+5;
const int LG = 18;//log2(MX)+1;
vector<int> g[MX];
vector<int> dep;
int par[LG][MX];
int n, m;

void pre(int u, int p, int d) {
    dep[u] = d;
    par[0][u] = p;
    for (auto &v : g[u]) {
        if (v != p) {
            pre(v, u, d + 1);
        }
    }
}

void build() {
    dep.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (dep[i] == -1) {
            pre(i, i, 0);
        }
    }
    for (int j = 0; j < LG-1; j++) {
        for (int i = 0; i < n; i++) {
            par[j+1][i] = par[j][ par[j][i] ];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = LG-1; i >= 0; i--) {
        if (dif & (1<<i)) {
            u = par[i][u];
        }
    }
    if (u == v) return u;
    for (int i = LG-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

ll f(ll x){
  return x*(x-1)/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  int u, v;
  forn(i, 0, n-1){
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  build();

  forn(i, 0, m){
    cin >> u >> v;
    u--, v--;
    int l = lca(u, v);
    int tot = dep[u] - dep[l] + dep[v] - dep[l] + 1;
    ll ans = n + f(tot);
    cout << ans << endl;
  }

  

}