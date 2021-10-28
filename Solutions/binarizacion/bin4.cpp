//https://codeforces.com/gym/102992/problem/M
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... E>
void debug(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");debug(e...);}
#define forn(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2005;
const ll inf = 1e18;
vector<int> g[N];
ll dp[N][N][2], temp[N][2];
int val[N], sz[N];
ll sum[N];
int n;

void init(){
  forn(i, 0, n){
    g[i].clear();
    forn(j, 0, n + 1){
      forn(k, 0, 2) dp[i][j][k] = 0;
    }
  }
}

void reset_temp(){
  forn(i, 0, n + 1){
    forn(j, 0, 2)temp[i][j] = inf;
  }
}

void dfs(int u){
  sz[u] = 1;
  if(g[u].empty()){
    dp[u][0][1] = inf;
    dp[u][0][0] = val[u];
    dp[u][1][0] = inf;
    dp[u][1][1] = 0;
    return;
  }
  for(int v: g[u]){
    dfs(v);
    reset_temp();
    forn(x, 0, sz[u] + 1){
      forn(y, 0, sz[v] + 1){
        // no spell
        if(x + y < sz[u] + sz[v]){
          temp[x + y][0] = min(temp[x + y][0], dp[u][x][0] + dp[v][y][0] + val[v]);
          temp[x + y][0] = min(temp[x + y][0], dp[u][x][0] + dp[v][y][1]);
        }
        // spell
        if(x){
          temp[x + y][1] = min(temp[x + y][1], dp[u][x][1] + dp[v][y][0]);
          temp[x + y][1] = min(temp[x + y][1], dp[u][x][1] + dp[v][y][1]);
        }
      }
    }
    sz[u] += sz[v];
    forn(x, 0, sz[u] + 1){
      dp[u][x][0] = temp[x][0];
      dp[u][x][1] = temp[x][1];
    }
  }
  forn(x, 0, sz[u] + 1) dp[u][x][0] += val[u];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);       

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    init();
    forn(v, 1, n){
      int u;
      cin >> u;
      u--;
      g[u].pb(v);
    }
    forn(i, 0, n)cin >> val[i];
    dfs(0);
    forn(i, 0, n + 1){
      cout << min(dp[0][i][0], dp[0][i][1]) << " \n"[i == n];
    }
  }


      
  
}
