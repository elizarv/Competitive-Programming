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

const int N = 1e4+5, inf = 1e9, LOG2 = 20;;
vector<int> g[N];
bitset<N> mask[N], neutro;
int dep[N], par[LOG2][N];


void dfs(int u, int p, int d, bitset<N> w){
	dep[u] = d;
	par[0][u] = p;
  mask[u] = w;
	for(int j = 1; j < LOG2; j++){
		par[j][u] = par[j-1][par[j-1][u]];
	}
	for(auto v: g[u]){
		if(v == p)continue;
    w[v] = 1;
		dfs(v, u, d+1, w);
    w[v] = 0;
	}
}

int lca(int u, int v){
	if(dep[v] < dep[u])swap(u, v);
	int d = dep[v]-dep[u];
	for(int j = LOG2-1; j >= 0; j--){
		if(d >> j & 1){
			v = par[j][v];
		}
	}
	if(u == v)return u;
	for(int j = LOG2-1; j >= 0; j--){
		if(par[j][u] != par[j][v]){
			u = par[j][u];
			v = par[j][v];
		}
	}
	return par[0][u];
}

void init(int n){
  forn(i, 0, n+1)g[i].clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  forn(i, 0, N)neutro[i] = 1;

  int t;
  cin >> t;
  for(int caso = 1; caso <= t; caso++){
    int n;
    cin >> n;
    init(n);
    forn(i, 1, n){
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(0, 0, 0, 1);
    cout << "Case " << caso << ":" << endl;
    int m;
    cin >> m;
    forn(i, 0, m){
      int k; cin >> k;
      bitset<N> ans = neutro;
      forn(j, 0, k){
        int u, v;
        cin >> u >> v;
        u--, v--;
        bitset<N> cur = mask[u]^mask[v];
        int l = lca(u, v);  
        cur[l] = 1;
        ans = ans&cur;
      }
      cout << ans.count() << endl;
    }
  }

}
