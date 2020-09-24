#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 21, M = (1<<N);
int mat[N][N], n, mod = 1e9 + 7;
ll dp[N][M];

ll f(int i, int mask){
  if(i == n){
    return !mask? 1: 0;
  }
  ll &ans  = dp[i][mask];
  if(ans != -1)return ans;
  ans = 0;
  forn(j, 0, n){
    if((mask >> j & 1) && mat[i][j]){
      ans = (ans + f(i+1, mask^(1 << j)))%mod;
    }
  }
  return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  forn(i, 0, n){
    forn(j, 0, n){
      cin >> mat[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  int mask = (1 << n)-1;
  cout << f(0, mask) << endl;

}



