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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int N = 2 * n + 2;

  network net(N);

  forn(i, 0, n){
    int u = 2*i, v = u+1;
    if(s[i] == 'P'){
      net.add_edge(0, u, 1);
    }else if(s[i] == '*'){
      net.add_edge(v, N-1, 1);
    }
    net.add_edge(u, v, 1);
    if(i){
      int prevu = 2 * (i-1), prevv = prevu + 1;
      net.add_edge(prevu, v, 1);
      net.add_edge(u,  prevv, 1);
    }
  }

  cout << net.max_flow(0, N-1) << endl;


}