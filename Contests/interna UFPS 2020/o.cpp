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
typedef pair<int, ll> pii;


const int N = 8, M = (1 << N)+1, inf  = 1e9;
pii dp[62][M][M];
bool vis[62][M][M];
int mat[62][62];
int n, m, target;
int dy[] = {1,1,0,-1,-1,-1, 0, 1};
int dx[] = {0,1,1, 1, 0,-1,-1,-1};

bool valid(int j, vector<int> v){
  if(j < 0)return true;
  int auxj = 1;
  forn(i, 0, n){
    int ans = 0;
    if(!mat[i][j])continue;
    forn(k, 0, 8){
      int nxti = i + dy[k];
      int nxtj = j + dx[k];
      if(nxti < 0 || nxti >= n || nxtj < 0 || nxtj >= m)continue;
      nxtj = auxj + dx[k];
      ans += (v[nxtj] >> nxti & 1);
    }
    if(ans != mat[i][j])return false;
  }
  return true;
}

bool check(int i, int mask){
  forn(k, 0, n){
    if((mask >> k) & 1 && mat[k][i])return true;
  }
  return false;
}
  
pii f(int i, int mask1, int mask2){
  if(i == m){
    if(valid(i-1, {mask1, mask2, 0}))return {0, 1};
    return {inf, 0};
  }
  pii &ans = dp[i][mask1][mask2];
  if(vis[i][mask1][mask2])return ans;
  vis[i][mask1][mask2] = true;
  ans = {inf, 0};
  forn(mask, 0, target){
    int sz = __builtin_popcount(mask);
    if(check(i, mask))continue;
    if(valid(i-1, {mask1, mask2, mask})){
      pii aux = f(i+1, mask2, mask);
      if(aux.F+sz == ans.F){
        ans.S += aux.S;
      }else ans = min(ans, {aux.F+sz, aux.S});
    }
  }
  return ans;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if(n < m){
    forn(i, 0, n){
      forn(j, 0, m){
        char ch;
        cin >> ch;
        if(ch != '.')mat[i][j] = ch-'0';
      }
    }
  }else{
    swap(n, m);
    forn(j, 0, m){
      forn(i, 0, n){
        char ch;
        cin >> ch;
        if(ch != '.')mat[i][j] = ch-'0';
      }
    }
  }

  target = (1 << n);

  memset(dp, -1, sizeof dp);
  pii ans = f(0, 0, 0);

  if(ans.F == inf)cout << "0" << endl;
  else{
    cout << ans.S << " " << ans.F << endl;
  }

}
