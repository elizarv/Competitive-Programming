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

const int N = 4e5+2, inf = 1e9, LOG2 = 20;
int dep[N], par[N][LOG2], in[N][LOG2], out[N][LOG2], mask[N][LOG2];
vector<int> g[N];

struct edge {
	int in, out, mask;
};
edge info[N];

void dfs(int u, int p, int d, int i, int o, int m){
	dep[u] = d;
	par[u][0] = p;
	in[u][0] = i;
	out[u][0] = o;
	mask[u][0] = m;
	forn(j, 1, LOG2){
		par[u][j] = par[par[u][j-1]][j-1];
		in[u][j] = max(in[u][j-1], in[par[u][j-1]][j-1]);
		out[u][j] = min(out[u][j-1], out[par[u][j-1]][j-1]);
		mask[u][j] = mask[u][j-1] & mask[par[u][j-1]][j-1];
	}
	for(int v: g[u]){
		if(v == p)continue;
		dfs(v, u, d+1, info[v].in, info[v].out, info[v].mask);
	}
}

int lca(int u, int v, int t){
	if(dep[v] < dep[u])swap(u, v);
	int d = dep[v]-dep[u];
	int mxi = info[u].in, mno = info[u].out;
	int ans = info[u].mask;
	for(int j = LOG2-1; j >= 0; j--){
		if(d >> j & 1){
			mxi = max(mxi, in[v][j]);
			mno = min(mno, out[v][j]);
			ans = ans & mask[v][j];
			v = par[v][j];
		}
	}
	if(u == v){
		if(t >= mxi && t <= mno)return __builtin_popcount(ans);
		return -1;
	}
	for(int j = LOG2-1; j >= 0; j--){
		if(par[u][j] != par[v][j]){
			mxi = max({mxi, in[u][j], in[v][j]});
			mno = min({mno, out[u][j], out[v][j]});
			ans = ans & mask[u][j] & mask[v][j];
			u = par[u][j];
			v = par[v][j];
		}
	}
	mxi = max({mxi, in[u][1], in[v][0]});
	mno = min({mno, out[u][1], out[v][0]});
	ans = ans & mask[u][1] & mask[v][0];
	if(par[u][0] != par[v][0])return -1;
	if(t >= mxi && t <= mno)return __builtin_popcount(ans);
	return -1;
}



struct query {
	int u, v, t;
};
vector<query> queries;

map<int, int> mapa;

int get(int u){
	int x = mapa.size();
	if(!mapa.count(u))mapa[u] = x;
	return mapa[u];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n, k, u, v;
	cin >> n >> k;
	int t = 0;
	forn(i, 0, n){
		cin >> u >> v;
		u = get(u);
		v = get(v);
		int k; cin >> k;
		int x, m = 0;
		forn(j, 0, k){
			cin >> x;
			x--;
			m |= (1<<x);
		}
		if(u != v){
			g[u].pb(v);
			g[v].pb(u);
		}
		info[u] = {t, inf, m};
		t++;
	}
	int q; cin >> q;

	forn(i, 0, q){
		int type; cin >> type;
		if(!type){
			cin >> u;
			u = get(u);
			info[u].out = t;
		}else if(type == 1){
			cin >> u >> v;
			u = get(u);
			v = get(v);
			queries.pb({u, v, t});
		}else{
			cin >> u >> v;
			u = get(u);
			v = get(v);
			int k; cin >> k;
			int x, m = 0;
			forn(j, 0, k){
				cin >> x;
				x--;
				m |= (1<<x);
			}
			if(u != v){
				g[u].pb(v);
				g[v].pb(u);
			}
			info[u] = {t, inf, m};
		}
		t++;
	}

	memset(dep, -1, sizeof dep);
	forn(i, 0, mapa.size()){
		if(dep[i] == -1)dfs(i, i, 0, info[i].in, info[i].out, info[i].mask);
	}

	for(auto qu: queries){
		u = qu.u;
		v = qu.v;
		t = qu.t;
		cout << lca(u, v, t) << endl;
	}

}