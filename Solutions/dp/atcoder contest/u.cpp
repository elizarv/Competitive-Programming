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

const int N = 17, M = 1<<N;
ll dp[M], cost[M];
int n, val[N][N];

ll f(int mask){
  if(mask == 0)return 0;
  ll &ans = dp[mask];
  if(ans != -1)return ans;
  ans = 0;
  for(int sub = mask; sub; sub = (sub-1)&mask){
    ans = max(ans, f(mask^sub)+cost[sub]);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;

  forn(i, 0, n){
    forn(j, 0, n){
      cin >> val[i][j];
    }
  }

  int mask = 1 << n;
  forn(sub, 0, mask){
    ll sum = 0;
    forn(i, 0, n){
      if(!(sub >> i & 1))continue;
      forn(j, i+1, n){
        if(!(sub >> j & 1))continue;
        sum += val[i][j];
      }
    }
    cost[sub] = sum;
  }
  
  memset(dp, -1, sizeof dp);
  cout << f(mask-1) << endl;



}



