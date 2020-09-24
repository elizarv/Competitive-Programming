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

const int MAX = 100005;
vector<int> g[MAX];
int dp[MAX], n, m;

int f(int u){
    int &ans = dp[u];
    if(ans != -1)return ans;
    ans = 0;
    for(int v: g[u]){
        ans = max(ans, f(v)+1);
    }
    return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int u, v;
  cin >> n >> m;
  forn(i, 0, m){
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
  }
  memset(dp, -1, sizeof dp);
  int ans = 0;
  forn(i, 0, n){
      if(dp[i]==-1)ans = max(ans, f(i));
  }
  cout << ans << endl;



}



