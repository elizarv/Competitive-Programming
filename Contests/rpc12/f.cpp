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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1005;
ll inf = 1e18;
ll dp[MX][MX];
ll w[MX];
int h[MX];


int n;

ll getArea(int i, int j, ll hh){
    ll wd = w[j];
    if(i)wd -= w[i-1];
    return wd * hh;
}

ll f(int i, int k){
    if(i == n){
        if(!k) return 0;
        return inf;
    }
    if(!k) return inf;
    ll &ans = dp[i][k];
    if(ans != -1)return ans;
    ans = inf;
    int mx = 0;
    forn(j, i, n-k+1){
        mx = max(mx, h[j]);
        ans = min(ans, f(j+1, k-1) + getArea(i, j, mx));
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> n >> k;


  forn(i, 0, n){
      cin >> w[i] >> h[i];
      if(i) w[i] += w[i-1];
  }

  memset(dp, -1, sizeof dp);
  cout << f(0, k) << endl;

  
}
