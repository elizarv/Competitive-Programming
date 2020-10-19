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

struct edge{
	int v, w, id;

	bool operator < (const edge& b) const {
		if(w == b.w)return id < b.id;
		return w < b.w;
	}
};

const int N = 505, inf = 1e9+1;
vector<edge> g[N];
ll dist[N];
pii par[N];
int n, c;

bool dijkstra(){
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
	forn(i, 0, n)dist[i] = inf;
	dist[0] = 0;
	pq.push({0, 0});

	while(pq.size()){
		int u = pq.top().S;
		int w = pq.top().F;
		pq.pop();
		if(dist[u] != w)continue;
		for(auto &nx: g[u]){
			int v = nx.v;
			int w = nx.w;
			int id = nx.id;
			if(dist[v] > dist[u]+w){
				dist[v] = dist[u]+w;
				par[v] = {u, id};
				pq.push({dist[v], v});
			}
		}
	}
	return dist[n-1] >= c;
}

vector<int> pipes;

void build(){
	int u = n-1;
	while(u != 0){
		pii p = par[u];
		pipes.pb(p.S+1);
		u = p.F;
	}
	sort(pipes.begin(), pipes.end());
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  // freopen("gas.in", "r", stdin);
  // freopen("gas.out", "w", stdout);
  
  int m;
  cin >> n >> m >> c;

	int u, v, w;
  forn(i, 0, m){
		cin >> u >> v >> w;
		u--, v--;
		g[u].pb({v, w, i});
		g[v].pb({u, w, i});
  }

	if(dijkstra())cout << "Fair" << endl;
	else{
		cout << "Unfair" << endl;
		build();
		n = pipes.size();
		cout << n << endl;
		forn(i, 0, n){
			cout << pipes[i] << " \n"[i+1 == n];
		}
	}


  
  

  
}