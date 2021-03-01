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

const int inf = 1e9;

struct edge { int v, cap, inv, flow; };
struct network {
  int n, s, t;
  vector<int> lvl;
  vector<vector<edge>> g;
  network(){}
  network(int n) : n(n), lvl(n), g(n) {}
  void add_edge(int u, int v, int c) {
    g[u].push_back({v, c, (int)g[v].size(), 0});
    g[v].push_back({u, 0, (int)g[u].size()-1, c});
  }
  bool bfs() {
    fill(lvl.begin(), lvl.end(), -1);
    queue<int> q;
    lvl[s] = 0;
    for(q.push(s); q.size(); q.pop()) {
      int u = q.front();
      for(auto &e : g[u]) {
        if(e.cap > 0 && lvl[e.v] == -1) {
          lvl[e.v] = lvl[u]+1;
          q.push(e.v);
        }
      }
    }
    return lvl[t] != -1;
  }
  int dfs(int u, int nf) {
    if(u == t) return nf;
    int res = 0;
    for(auto &e : g[u]) {
      if(e.cap > 0 && lvl[e.v] == lvl[u]+1) {
        int tf = dfs(e.v, min(nf, e.cap));
        res += tf; nf -= tf; e.cap -= tf;
        g[e.v][e.inv].cap += tf;
        g[e.v][e.inv].flow -= tf;
        e.flow += tf;
        if(nf == 0) return res;
      }
    }
    if(!res) lvl[u] = -1;
    return res;
  }
  int max_flow(int so, int si, int res = 0) {
    s = so; t = si;
    while(bfs()) res += dfs(s, INT_MAX);
    return res;
  }
};


struct path{
  int u, v, t;
};

vector<path> p;
vector<int> a, b;

network net;
int N, n, m, tot;

void build(int t){
  net = network(N);
   int tot = 0;
  forn(i, 1, n+1){
    net.add_edge(i, N-1, a[i-1]);
  }

  forn(i, 1, m+1){
    net.add_edge(0, i + n, b[i-1]);
  }

  for(auto &x: p){
    if(x.t <= t){
      net.add_edge(x.v + n, x.u, inf);
    }
  }

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int q;
  cin >> n >> m >> q;

  N = n + m + 2;
  tot = 0;

  forn(i, 0, n){
    int x; cin >> x;
    a.pb(x);
    tot += x;
  }

  forn(i, 0, m){
    int x; cin >> x;
    b.pb(x);
  }
  int mx = 0;

  forn(i, 0, q){
    int u, v, t;
    cin >> u >> v >> t;
    p.pb({u, v, t});
    mx = max(mx, t);
  }

  int l = 0, r = mx+1;
  
  while(l < r){
    int mid = (l + r) / 2;
    build(mid);
    if(net.max_flow(0, N-1) == tot)r = mid;
    else l = mid + 1;
  }

  build(l);

  if(net.max_flow(0, N-1) < tot)cout << "-1" << endl;
  else cout << l << endl;




}