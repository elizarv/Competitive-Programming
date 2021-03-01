#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}

struct edge {
    int u, v, cap, flow, cost;
    int rem() { return cap - flow; }
};


const int inf = 1e9;
const int MX = 210;
int d[MX][MX], P[MX], Q[MX];
vector<int> g[MX];
vector<edge> e;
vector<bool> in_queue;
vector<int> pre, dist, cap;
int mxflow, mncost;
int n, m, s, t;
int N;

void add_edge(int u, int v, int cap, int cost) {
    g[u].push_back(e.size());
    e.push_back({u, v, cap, 0, cost});
    g[v].push_back(e.size());
    e.push_back({v, u, 0, 0, -cost});
}

void flow(int s, int t) {
    mxflow = mncost = 0;
    in_queue.assign(N, false);
    while (true) {
        dist.assign(N, inf); dist[s] = 0;
        cap.assign(N, 0); cap[s] = inf;
        pre.assign(N, -1); pre[s] = 0;
        queue<int> q; q.push(s);
        in_queue[s] = true;
        
        while (q.size()) {
            int u = q.front(); q.pop();
            in_queue[u] = false;
            for (int &id : g[u]) {
                edge &ed = e[id];
                int v = ed.v;
                if (ed.rem() && dist[v] > dist[u]+ed.cost) {
                    dist[v] = dist[u]+ed.cost;
                    cap[v] = min(cap[u], ed.rem());
                    pre[v] = id;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                    }
                }
            }
        }
        if (pre[t] == -1) break;
        mxflow += cap[t];
        mncost += cap[t] * dist[t];
        for (int v = t; v != s; v = e[pre[v]].u) {
            e[pre[v]].flow += cap[t];
            e[pre[v]^1].flow -= cap[t];
        }
    }
}


void build_graph(int mx){
  e.clear();
  forn(i, 0, N)g[i].clear();
  forn(i, 1, n+1){
    add_edge(s, i, P[i], 0);
    add_edge(i+n, t, Q[i], 0);
  }
  forn(i, 1, n+1){
    forn(j, 1, n+1){
      if(d[i][j] <= mx){
        add_edge(i, j+n, inf, 0);
      }
    }
  }
}

void init(){
  for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
          d[i][j] = (i == j ? 0 : inf);
      }
  }
}

void floydWarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;

  cin >> n >> m >> x;
  forn(i, 1, n+1) cin >> P[i];
  forn(i, 1, n+1) cin >> Q[i];
  init();
  forn(i, 0, m){
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }

  floydWarshall();

  N = n*2+3;
  s = 0, t = N-1;

  build_graph(x);
  flow(s, t);
  int mx = mxflow;

  int l = 0, r = x;
  while(l < r){
    int m = (l+r)/2;
    build_graph(m);
    flow(s, t);
    if(mxflow == mx)r = m;
    else l = m+1;
  }

  cout << l << " " << mx << endl;
}