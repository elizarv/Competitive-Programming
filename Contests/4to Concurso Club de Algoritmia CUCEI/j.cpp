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

const int MX = 1e4+5, MXM = 15, MOD = 1e9+7;
int dp[MX][MXM][MXM];
int N, M, K;

int add(ll a, ll b){
  if(a + b < MOD)return a + b;
  return a + b - MOD;
}

int mult(ll a, ll b){
  return (a * b) % MOD;
}

int f(int i, int j, int k){
  if(i == N)return k <= M;
  if(k > M)return 0;
  int &ans = dp[i][j][k];
  if(ans != -1)return ans;
  ans = 0;
  forn(col, 1 , K+1){
    if(col == j) ans = add(ans, f(i+1, col, k+1));
    else ans = add(ans, f(i+1, col, 1));
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N >> K >> M;
  memset(dp, -1, sizeof dp);
  int ans = f(0, 0, 0);
  cout << ans << endl;

  
  
}