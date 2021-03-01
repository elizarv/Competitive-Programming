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
typedef double lf;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll d;

  cin >> n >> d;
  ll mn = 1e18, mx = -1e18;

  vector<ll> lf(n), rg(n);
  forn(i, 0, n){
    cin >> lf[i];
  }
  rg = lf;
  reverse(rg.begin(), rg.end());

  forn(i, 0, n)lf[i] -= i*d;
  sort(lf.begin(), lf.end());

  forn(i, 0, n)rg[i] -= i*d;
  sort(rg.begin(), rg.end());

  ll ans = min(rg[n-1]-rg[0], lf[n-1]-lf[0]);

  ll mod = 0;
  if(ans&1)mod = 5;
  ans /= 2;
  
  cout << ans << "." << mod << endl;

  

}