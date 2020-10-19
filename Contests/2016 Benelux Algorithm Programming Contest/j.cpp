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

const int N = 105;
int n;
pii a[N], b[N];

struct mbm {
  int l, r;
  vector<vector<int>> g;
  vector<int> match, vis;
  
  mbm(int l, int r) : l(l), r(r), g(l) {}

  void add_edge(int l, int r) { g[l].pb(r);}

  bool dfs(int u) {
    for (auto &v: g[u]) {
      if (vis[v]++) continue;
      if(match[v] == -1 || dfs(match[v])) {
        match[v] = u; 
        return true;
      }
    }
    return false;
  }

  int max_matching() {
    int ans = 0;
    match.assign(r, -1);
    for (int u = 0; u < l; ++u) {
      vis.assign(r, 0);
      ans += dfs(u);
    }
    return ans;
  }
};

bool check(int x) {
  int dis, ans = 0;
  mbm mat(n, n);
  forn (i, 0, n) {
    forn (j, 0, n) {
      dis = abs(a[i].F - b[j].F) + abs(a[i].S - b[j].S);
      if (dis <= x) {
        mat.add_edge(i, j);
      }
    }
  }
  return mat.max_matching() == n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
  cin >> n;
  forn(i, 0, n) cin >> a[i].F >> a[i].S;
  forn(i, 0, n) cin >> b[i].F >> b[i].S;
  int l = 0, r = 1e9, m;
  while (l +  1 < r) {
    m = (l + r) / 2;
    if (!check(m)) l = m;
    else r = m;
  }
  if (check(l)) cout << l << endl;
  else cout << r << endl;
}