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

const int N = 105, K = 1e5 + 5;
int val[N], mod = 1e9 + 7, n, m;
ll dp[N][K];

ll f(int i, int k){
  if(i == n)return !k;
  ll &ans = dp[i][k];
  if(ans != -1)return ans;
  ans = 0;
  int R = min(val[i], k)+1;
  forn(j, 0, R){
    ans += f(i+1, k-j);
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  forn(i, 0, n)cin >> val[i];
  memset(dp, -1, sizeof dp);

}



