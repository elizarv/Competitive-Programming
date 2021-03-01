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

const int N = 5e4+5, inf = 1e9;
vector<int> g[N];
int par[N], dep[N], sz[N], dist[20][N];
pii company[2*N];
set<int> qrs;
int n;

int pre(int u, int p){
  sz[u] = 1;
  for(int &v: g[u]){
    if(v == p || dep[v])continue;
    sz[u] += pre(v, u);
  }
  return sz[u];
}

int centroid(int u, int p, int k){
  for(auto &v: g[u]){
    if(v == p || dep[v]) continue;
    if(sz[v] > k) return centroid(v, u, k);
  }
  return u;
} 

struct node {
  vector<pii> v = {};
  int mx, lg;
  vector<vector<int>> st;

  void build(){
    sort(v.begin(), v.end());
    mx = v.size();
    lg = log2(mx)+1;
    st = vector<vector<int>>(lg, vector<int>(mx+1, inf));
    forn(i, 0, mx)st[0][i] = v[i].S;
    forn(j, 1, lg){
      for(int i = 0; i+(1<<(j-1)) <= mx; i++){
        st[j][i] = min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
      }
    }
  }

  int rmq(int a, int b){
    int i = lower_bound(v.begin(), v.end(), make_pair(a, -1)) - v.begin();
    int j = upper_bound(v.begin(), v.end(), make_pair(b, inf)) - v.begin()-1;
    if(i > j)return inf;
    int k = 31-__builtin_clz(j-i+1);
    return min(st[k][i], st[k][j-(1<<k)+1]);
  }

  void init(){
    v.clear();
    st.clear();
  }

};

int root, lvl;
node tree[N];

void dfs(int u, int p, int d){
  tree[root].v.pb({u, d});
  dist[lvl][u] = d;
  for(int &v: g[u]){
    if(v == p || dep[v])continue;
    dfs(v, u, d+1);
  }
}

void go(int u, int p, int d){
  root = u;
  lvl = d;
  dfs(u, p, 0);
  tree[u].build();
}

void build(int u, int p = -1, int d = 1){
  int k = pre(u, p);
  int c = centroid(u, p, k/2);
  par[c] = p, dep[c] = d;
  go(c, p, d);
  for(int &v: g[c]){
    if(!dep[v])build(v, c, d+1);
  }
}

int getdist(int u, int v, int lvl){
  return dist[lvl][u] + dist[lvl][v];
}

void query(){
  int c, m, p;
  cin >> c >> m;
  c--;
  int ans = inf;
  forn(i, 0, m){
    cin >> p;
    pii range = company[p];
    if(range == make_pair(-1, -1))continue;
    int a = c;
    while(a != -1){
      ans = min(ans, tree[a].rmq(range.F, range.S)+getdist(a, c, dep[a]));
      a = par[a];
    }
  }

  if(ans == inf)ans = -1;
  cout << ans << endl;
}

void init(){
  forn(i, 0, n+1){
    g[i].clear();
    sz[i] = dep[i] = par[i] = 0;
    tree[i].init();
  }
  for(auto &x: qrs){
    company[x] = {-1, -1};
  }
  qrs.clear();
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  forn(i, 0, 2*N){
    company[i] = {-1, -1};
  }

  int t, caso = 1;
  cin >> t;
  while(t--){
    cin >> n;
    init();
    forn(i, 1, n){
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    build(0);
    int q;
    cin >> q;
    cout << "Case " << caso++ << ":" << endl; 
    forn(i, 0, q){
      int e;
      cin >> e;
      if(e == 1){
        int x, l, r;
        cin >> x >> l >> r;
        l--, r--;
        company[x] = {l, r};
        qrs.insert(x);
      }else if(e == 2){
        int x;
        cin >> x;
        qrs.erase(x);
        company[x] = {-1, -1};
      }else{
        query();
      }
    }
  }

}