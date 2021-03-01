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

const int N = 5005;
vector<int> g[N];
bitset<N> vis;
int n, m, in[N];
map<string, int> mapa;

void init(){
  mapa.clear();
  vis = 0;
  forn(i, 0, n+1){
    g[i].clear();
    in[i] = 0;
  }
}

int dfs(int u, int p){
  int ans = 1;
  vis[u] = 1;
  for(int &v: g[u]){
    if(v == p || vis[v])continue;
    ans += dfs(v, u);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  while(cin >> n >> m){
    if(!n && !m)break;
    int cnt = 0;
    forn(i, 0, n){
      string s;
      cin >> s;
      mapa[s] = cnt++;
    }
    forn(i, 0, m){
      string a, b;
      cin >> a >> b;
      int u = mapa[a];
      int v = mapa[b];
      g[v].pb(u);
      g[u].pb(v);
    }
    int ans = 0;
    forn(i, 0, n){
      if(!vis[i] && !in[i])ans = max(ans, dfs(i, -1));
    }
    cout << ans << endl;

    init();
  }



}