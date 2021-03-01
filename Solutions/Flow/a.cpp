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

const int INF = 1e9;

struct edge { int v, cap, inv, flow; };
struct network {
  int n, s, t;
  vector<int> lvl;
  vector<vector<edge>> g;
  network(int n) : n(n), lvl(n), g(n) {}
  void add_edge(int u, int v, int c) {
    g[u].push_back({v, c, g[v].size(), 0});
    g[v].push_back({u, 0, g[u].size()-1, c});
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


int N = 0;
map<string, int> mapa;

int getpos(string s){
  int p = mapa.size();
  if(!mapa.count(s))mapa[s] = p;
  return mapa[s];
}

const int N = 1e5+5;
vector<int> v[N];

struct node {
  int next[N], end;
  int& operator[] (int i) { return next[i]; }
};

vector<node> trie = {node()};

void add(vector<int>& num){
  int u = 0;
  for(int x: num){
    if(!trie[u][x]){
      trie[u][x] = trie.size();
      trie.pb(node());
    }
    u = trie[u][x];
  }
  trie[u].end = true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;


  forn(i, 0, n){
    int m;
    forn(j, 0, m){
      string s;
      cin >> s;
      int p = getpos(s);
      v[i].pb(p);
    }
  }

  forn(i, 0, n){
    int sz = v[i].size();
    forn(mask, 0, 1 << sz){
      for(int sub = mask; sub; sub = (sub-1)&mask){
        
      }
    }
  }

}