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

const int N = 405;
ll psum[N], dp[N][N], val[N], inf = 1e18;
int n;

ll cost(int i, int j){
  if(i-1 >= 0)return psum[j]-psum[i-1];
  return psum[j];
}

ll f(int i, int j){
  if(i == j)return 0;
  ll &ans  = dp[i][j];
  if(ans != -1)return ans;
  ans = inf;
  forn(k, i, j+1){
    ans = min(ans, f(i, k)+f(k+1, j)+cost(i, j));
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  forn(i, 0, n){
    cin >> val[i];
    psum[i] = val[i];
    if(i)psum[i] += psum[i-1];
  }
  memset(dp, -1, sizeof dp);
  cout << f(0, n-1) << endl;


}



