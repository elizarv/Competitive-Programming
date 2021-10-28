//https://codeforces.com/contest/815/problem/C
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

const int N = 5005;
const ll inf = 1e18;
vector<int> g[N];
ll dp[N][N][2], temp[N][2];
int cost[N], bonus[N], sz[N];
ll sum[N], b;

void reset_temp(int sz){
  forn(i, 0, sz + 1){
    forn(j, 0, 2)temp[i][j] = inf;
  }
}

void dfs(int u){
  sz[u] = 1;
  dp[u][0][0] = 0;
  dp[u][0][1] = inf;
  dp[u][1][0] = cost[u];
  dp[u][1][1] = bonus[u];
  for(int v: g[u]){
    dfs(v);
    reset_temp(sz[u] + sz[v]);
    forn(x, 0, sz[u] + 1){
      forn(y, 0, sz[v] + 1){
        // bono
        if(x){
          temp[x + y][1] = min(temp[x + y][1], dp[u][x][1] + dp[v][y][0]);
          temp[x + y][1] = min(temp[x + y][1], dp[u][x][1] + dp[v][y][1]);
        }
        //no bono
        temp[x + y][0] = min(temp[x + y][0], dp[u][x][0] + dp[v][y][0]);
      }
    }
    sz[u] += sz[v];
    forn(x, 0, sz[u] + 1){
      dp[u][x][0] = temp[x][0];
      dp[u][x][1] = temp[x][1];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);       

  int n;

  cin >> n >> b;
  forn(v, 0, n){
    int x, u;
    cin >> cost[v] >> x;
    bonus[v] = cost[v] - x;
    if(v){
      cin >> u;
      u--;
      g[u].pb(v);
    }
  }
  dfs(0);

  int ans = 0;

  forn(x, 0, n + 1){
    ll aux = min(dp[0][x][0], dp[0][x][1]);
    if(aux <= b)ans = x;
  }

  cout << ans << endl;

  
}