// https://codeforces.com/contest/1324/problem/F

#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;
vector<int> g[MAX];
int val[MAX];
int ans[MAX];

void dfs1(int u, int p){
    ans[u] = val[u];
    
    for(int v: g[u]){
        if(v == p)continue;
        dfs1(v, u);
        if(ans[v] > 0)ans[u] += ans[v];
    }
}

void dfs2(int u, int p, int upch){
    if(upch > 0) ans[u] += upch;
    for(int v: g[u]){
        if(v == p)continue;
        int nxt = ans[u];
        if(ans[v] > 0)nxt -= ans[v];
        dfs2(v, u, nxt);
    }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, u, v;
  cin >> n;

  forn(i, 0, n){
      cin >> val[i];
      if(!val[i])val[i]--;
  }

  forn(i, 0, n-1){
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
  }

  dfs1(0, -1);
  dfs2(0, -1, 0);

  forn(i, 0, n){
      cout << ans[i] << " \n"[i+1 == n];
  }

  
}
