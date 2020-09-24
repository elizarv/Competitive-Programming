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


struct BIT {
  int n;
  vector<ll> bit;
  BIT(int _n){ 
    n = _n+1;
    bit.assign(n, 0);
  }

  void set(int k, ll val){
    for(; k <=n; k += k&-k) bit[k] = max(bit[k], val);
  }

  ll rmq(int k){
    ll mx = 0;
    for(; k > 0; k -= k&-k) mx = max(mx, bit[k]);
    return mx;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<int> h(n), a(n);
  int mx = 0;
  forn(i, 0, n){
    cin >> h[i];
    mx = max(mx, h[i]);
  }
  forn(i, 0, n)cin >> a[i];

  BIT bit(mx+1);

  ll ans = 0;
  forn(i, 0, n){
    ll x = 0;
    if(h[i] > 1)x = bit.rmq(h[i]-1);
    ll y = bit.rmq(h[i]);
    if(y < x+a[i]){
      bit.set(h[i], x+a[i]);
      ans = max(ans, x+a[i]);
    }
  }

  cout << ans << endl;



}



