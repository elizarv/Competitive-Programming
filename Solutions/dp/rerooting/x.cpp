// https://codeforces.com/contest/766/problem/E

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

const int MAX = 100005, N = 20;
vector<int> g[MAX];
int val[MAX][20], sz[MAX];
int dp[MAX][20];
ll ans[20];

void dfs1(int u, int p){
    forn(i, 0, N){
        dp[u][i] = val[u][i];
    }
    sz[u] = 1;
    for(int v: g[u]){
        if(v == p)continue;
        dfs1(v, u);
        sz[u] += sz[v];

        forn(i, 0, N){
            int cnt;
            if(val[u][i])cnt = sz[v]-dp[v][i];
            else cnt = dp[v][i];
            dp[u][i] += cnt;
        }
    }
}

void dfs(int u, int p, int szup, vector<int>& upch){
    forn(i, 0, N){
        int cnt;
        if(val[u][i])cnt = szup-upch[i];
        else cnt = upch[i];
        dp[u][i] += cnt;
        ans[i] += dp[u][i];
    }
    for(int v: g[u]){
        if(v == p)continue;
        int SZ = sz[u]-sz[v]+szup;
        vector<int> next(N, 0);
        forn(i, 0, N){
            int cnt;
            if(val[u][i])cnt = sz[v]-dp[v][i];
            else cnt = dp[v][i];
            next[i] = dp[u][i]-cnt;
        }
        dfs(v, u, SZ, next);
    }
}







int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, u, v, x;
  cin >> n;

  forn(i, 0, n){
      cin >> x;
      forn(j, 0, N){
          if(x&(1<<j))val[i][j] = 1;
      }
  }

  


  forn(i, 0, n-1){
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
  }
  

  dfs1(0, -1);

  vector<int> up(N, 0);

  dfs(0, -1, 0, up);


  forn(i, 0, n){
      forn(j, 0, N){
          ans[j] += val[i][j];
      }
  }

  ll r = 0;
  int p = 1;

  forn(i, 0, N){
      r += p*(ans[i]/2);
      p *= 2;
  }

cout << r << endl;




  
}
