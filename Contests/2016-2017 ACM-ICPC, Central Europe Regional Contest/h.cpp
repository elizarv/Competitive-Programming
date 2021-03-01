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

const int MX = 1e6 + 5, inf = 1e9;
const int LG = 30;
vector<pii> G[MX];
int dep[MX];
int par[LG][MX], rmq[LG][MX];
int n, m;

void dfs(int u, int p, int d, int w){
	dep[u] = d;
	par[0][u] = p;
	rmq[0][u] = w;
	for(int j = 1; j < LG; j++){
		par[j][u] = par[j-1][par[j-1][u]];
		rmq[j][u] = min(rmq[j-1][u], rmq[j-1][par[j-1][u]]);
	}
	for(auto &ed: G[u]){
		int v = ed.F;
		int val = ed.S;
		if(v == p)continue;
		dfs(v, u, d+1, val);
	}
}

int lca (int u, int v) {
	int ans = inf;
  if (dep[u] < dep[v]) swap(u, v);
  int dif = dep[u] - dep[v];
  for (int i = LG - 1; i >= 0; i--) {
    if (dif & (1 << i)) {
			ans = min(ans, rmq[i][u]);
      u = par[i][u];
    }
  }
  if (u == v) return ans;
  for (int i = LG - 1; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
			ans = min({ans, rmq[i][u], rmq[i][v]});
      u = par[i][u];
      v = par[i][v];
    }
  } 
  return min({ans, rmq[0][u], rmq[0][v]});
}

const int N = 1010;
string g[N];
int d[N][N], comp[N][N], cnt;
int dx[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int _n;


void flood(int i, int j, int pi, int pj, int val){
  comp[i][j] = cnt;
  forn(k, 0, 4){
    int x = i+dx[k];
    int y = j+dy[k];
    if(x < 0 || y < 0 || x == _n || y == _n)continue;
    if(x == pi && y == pj)continue;
    if(d[x][y] == val && comp[x][y] == -1){
      flood(x, y, i, j, val);
    }
  }
}

set<pair<int, pii>> edges;

struct dsu {
    vector<int> par, sz;
    dsu(int n){
        par.resize(n);
        sz.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u){
        return par[u] == u ? u : (par[u] = find(par[u]));
    }

    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v)return false;
        if(sz[v] > sz[u])swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main h.cpp && ./main < h.txt

  cin >> _n;

  string s;

  forn(i, 0, _n+2)s = '#'+ s;
  g[0] = s;
  g[_n+1] = s;

  forn(i, 1, _n+1){
    cin >> s;
    s = '#'+ s + '#';
    g[i] = s;
  }

  memset(comp, -1, sizeof comp);

  _n += 2;
  queue<pii> q;
  forn(i, 0, _n){
    forn(j, 0, _n){
      d[i][j] = inf;
      if(g[i][j] == '#'){
        q.push({i, j});
        d[i][j] = 0;
        comp[i][j] = 0;
      }
    }
  }
  cnt++;

  //dist
  while(q.size()){
    int x = q.front().F;
    int y = q.front().S;
    q.pop();
    forn(k, 0, 8){
      int _x = x+dx[k];
      int _y = y+dy[k];
      if(_x < 0 || _y < 0 || _x == _n || _y == _n)continue;
      if(d[_x][_y] == inf){
        d[_x][_y] = d[x][y]+ 1 + (d[x][y] != 0);
        q.push({_x, _y});
      }
    }
  }

  //comp
  forn(i, 0, _n){
    forn(j, 0, _n){
      if(comp[i][j] == -1){
        flood(i, j, i, j, d[i][j]);
        cnt++;
      }
    }
  }

  //make g
  forn(i, 0, _n){
    forn(j, 0, _n){
      forn(k, 0, 4){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(nx < 0 || nx == _n || ny < 0 || ny == _n)continue;
          int u = comp[i][j];
          int v = comp[nx][ny];
					if(u == v)continue;
          int w = min(d[i][j], d[nx][ny]);
          edges.insert({-w, minmax(u, v)});
      }
    }
  }

  dsu dsu(cnt);

  for(auto &ed: edges){
      int u = ed.S.F;
      int v = ed.S.S;
      int w = ed.F;
      u = dsu.find(u);
      v = dsu.find(v);
      if(dsu.merge(u, v)){
        G[u].pb({v, -w});
        G[v].pb({u, -w});
      }
  }

  n = cnt;
  dfs(0, 0, 0, inf);
  int _m; cin >> _m;
  int ax, ay, bx, by;
  forn(i, 0, _m){
    cin >> ax >> ay >> bx >> by;
    int u = comp[ax][ay];
    int v = comp[bx][by];
		if(u == v)cout << d[ax][ay] << endl;
		else cout << lca(u, v) << endl;
  }

}