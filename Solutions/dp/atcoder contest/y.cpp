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

const int H = 1e5+5, W = 1e5+5, N = 3005, MOD = 1e9 + 7;
vector<pii> bad;
ll dp[N];
int h, w, n;
ll fac[2*H];

ll inv(ll b, int e){
  ll ans = 1;
  while(e){
    if(e&1)ans = (ans*b)%MOD;
    b = (b*b)%MOD;
    e /= 2;
  }
  return ans;
}

ll pascal(int c, int r){
  ll den = (fac[r]*fac[c-r])%MOD;
  den = inv(den, MOD-2);
  ll ans = (fac[c]*den)%MOD;
  return ans;
}

ll f(int i){
  ll &ans  = dp[i];
  if(ans != -1)return ans;
  ans = 0;
  ans = pascal(bad[i].F+bad[i].S, bad[i].S);
  forn(j, 0, n+1){
    if(j == i)continue;
    if(bad[i].F < bad[j].F || bad[i].S < bad[j].S)continue;
    int dx = bad[i].F-bad[j].F;
    int dy = bad[i].S-bad[j].S;
    ll out = pascal(dx+dy, dy);
    ans = (ans - (f(j) * out) % MOD + MOD) % MOD;
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> h >> w >> n;
  int r, c;
  bad.pb({h-1, w-1});
  forn(i, 0, n){
    cin >> r >> c;
    r--, c--;
    bad.pb({r, c});
  }
  fac[0] = 1;
  forn(i, 1, 2*H){
    fac[i] = (fac[i-1]*i)%MOD;
  }
  memset(dp, -1, sizeof dp);

  cout << f(0) << endl;





}



