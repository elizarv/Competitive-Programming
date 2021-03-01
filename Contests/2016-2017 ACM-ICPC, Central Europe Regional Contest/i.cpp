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

const int MX = 20, mod = 13;
ll inv[MX];
void invmod(ll m = mod) {
    inv[1] = 1;
    for(int i = 2; i <= MX; i++)
        inv[i] = m - (m/i) * inv[m%i] % m;
}

int add(int a, int b){
  if(a + b < mod)return a + b;
  return a + b - mod;
}

int sub(int a, int b){
  if(a - b < 0)return a - b + mod;
  return a - b;
}

int mul(int a, int b){
  if(a * b < mod)return a * b;
  return (a * b) % mod;
}

int divide(int a, int b){
  return mul(a, inv[b]);
}

const int EPS = 1;
int gauss (vector<vector<int>>& a, vector<int> &ans) {
  int n = a.size(), m = a[0].size()-1;
  vector<int> where(m, -1);
  for(int col = 0, row = 0; col < m && row < n; ++col) {
    int sel = row;
    for(int i = row; i < n; ++i)
      if(abs(a[i][col]) > abs(a[sel][col])) sel = i;
    if(abs(a[sel][col]) < EPS) continue;
    swap(a[sel], a[row]);
    where[col] = row;
    for(int i = 0; i < n; ++i)
      if(i != row) {
        int c = divide(a[i][col], a[row][col]); 
        for(int j = col; j <= m; ++j)
          a[i][j] = sub(a[i][j], mul(a[row][j], c));
      }
    ++row;
  }
  ans.assign(m, 0);
  for(int i = 0; i < m; ++i)
    if(where[i] != -1) ans[i] = divide(a[where[i]][m], a[where[i]][i]);
  for(int i = 0; i < n; ++i) {
    int sum = 0;
    for(int j = 0; j < m; ++j)
      sum = add(sum, mul(ans[j], a[i][j]));
    if(sum != a[i][m]) return 0;
  }
  for(int i = 0; i < m; ++i)
    if(where[i] == -1) return -1; 
  return 1;
}


const int N = 201;
int id[N][N], dist[N];
pii back[N];
vector<pii> g[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  invmod();

  int n, a, r, t;
  cin >> n >> a >> r >> t;
  a--, r--;
  vector<vector<int>> mat(t, vector<int> (N, 0));
  memset(id, -1, sizeof id);
  int pos = 0;
  
  forn(i, 0, t){
    int x, m, prev, nxt;
    cin >> x >> m >> prev;
    mat[i][N-1] = x;
    prev--;
    forn(j, 1, m){
      cin >> nxt;
      nxt--;
      pii nx = {prev, nxt};
      if(prev > nxt)swap(nx.F, nx.S);
      if(id[nx.F][nx.S] == -1){
        id[nx.F][nx.S] = pos;
        back[pos] = {nx.F, nx.S};
        pos++;
      }
      mat[i][id[nx.F][nx.S]] = add(mat[i][id[nx.F][nx.S]], 1);
      prev = nxt;
    }
  }
  vector<int> ans;

  gauss(mat, ans);
  
  int m = ans.size();
  forn(i, 0, m){
    if(!ans[i])continue;
    int u = back[i].F, v = back[i].S;
    g[u].pb({v, ans[i]});
    g[v].pb({u, ans[i]});
  }

  int mn;

  memset(dist, -1, sizeof dist);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, a});
  dist[a] = 0;
  while(pq.size()){
    int u = pq.top().S;
    int d = pq.top().F;
    pq.pop();
    if(u == r){
      mn = d;
      break;
    }
    if(dist[u] < d)continue;
    for(auto &nx: g[u]){
      int v = nx.F, w = nx.S;
      if(dist[v] == -1 || dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  cout << mn << endl;



}