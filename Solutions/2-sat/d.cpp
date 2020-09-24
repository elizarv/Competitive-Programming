//https://codeforces.com/problemset/problem/27/D
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
typedef unsigned long long ull;
typedef pair<int, int> pii;

struct sat2 {
  int n;
  vector<vector<vector<int>>> g;
  vector<int> tag;
  vector<bool> seen, value;
  stack<int> st;
  sat2(int n) : n(n), g(2, vector<vector<int>>(2*n)), tag(2*n), seen(2*n), value(2*n) { }
  int neg(int x) { return 2*n-x-1; }
  void add_or(int u, int v) { implication(neg(u), v); }
  void make_true(int u) { add_edge(neg(u), u); }
  void make_false(int u) { make_true(neg(u)); }
  void eq(int u, int v) {
    implication(u, v);
    implication(v, u);
  }
  void diff(int u, int v) { eq(u, neg(v)); }
  void implication(int u, int v) {
    add_edge(u, v);
    add_edge(neg(v), neg(u));
  }
  void add_edge(int u, int v) {
    g[0][u].push_back(v);
    g[1][v].push_back(u);
  }
  void dfs(int id, int u, int t = 0) {
    seen[u] = true;
    for(auto& v : g[id][u])
      if(!seen[v])
        dfs(id, v, t);
    if(id == 0) st.push(u);
    else tag[u] = t;
  }
  void kosaraju() {
    for(int u = 0; u < n; u++) {
      if(!seen[u]) dfs(0, u);
      if(!seen[neg(u)]) dfs(0, neg(u));
    }
    fill(seen.begin(), seen.end(), false);
    int t = 0;
    while(!st.empty()) {
      int u = st.top(); st.pop();
      if(!seen[u]) dfs(1, u, t++);
    }
  }
  bool satisfiable() {
    kosaraju();
    for(int i = 0; i < n; i++) {
      if(tag[i] == tag[neg(i)]) return false;
      value[i] = tag[i] > tag[neg(i)];
    }
    return true;
  }

  void print(){
    forn(i, 0, n){
      if(value[i])cout << "i";
      else cout << "o";
    }cout << endl;
  }
};

bool cross(pii r1, pii r2){
  int x = r1.F, y = r1.S, a = r2.F, b = r2.S;
  if(x == a || x == b || y == a || y == b)return false;
  if(a > x && a < y){
    if(b > x && b < y)return false;
    return true;
  }else{
    if(b > x && b < y)return true;
    return false;
  }
  return false;
}

int main() {
 ios::sync_with_stdio(0); cin.tie(0);

  int n, m, x, y;
  cin >> n >> m;

  vector<pii> roads;

  forn(i, 0, m){
    cin >> x >> y;
    roads.pb({minmax(x, y)});
  }

  sat2 sat(m);

  forn(i, 0, m){
    auto r1 = roads[i];
    forn(j, i+1, m){
      auto r2 = roads[j];
      if(cross(r1, r2)){
        sat.diff(i, j);
      }
    }
  }

  if(!sat.satisfiable())cout << "Impossible" << endl;
  else{
    sat.print();
  }




 }
