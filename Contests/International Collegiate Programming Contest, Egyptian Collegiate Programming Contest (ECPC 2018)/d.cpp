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

const int MX = 1e5+5, MOD = 1e9 + 7;
int d[MX], r[MX], inv[MX], v[MX];

int add (ll a, ll b){
	if (a + b < MOD) return a + b;
	return a + b - MOD;
}

int sub(ll a, ll b){
	if(a - b < 0)return a - b + MOD;
	return a - b;
}

int mult(ll a, ll b){
	return (a * b) % MOD;
}

int expmod(int b, int e, int m = MOD) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

int invmod(int a, int m = MOD) {
    return expmod(a, m-2, m);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
//   freopen("lcm.in", "r" , stdin);

	forn(i, 0, MX){
		inv[i] = invmod(i);
	}

  int t;
  cin >> t;
  while(t--){
	  int n, x, mx = 0;
	  cin >>  n;

	  forn(i, 0, n){
		  cin >> x;
		  mx = max(mx, x);
			v[x] += x;
			d[x] += x;
	  }

		ll ans = 0;

	  for(int x = mx; x; x--){
			int aux = mult(d[x], d[x]);
			aux = sub(aux, r[x]);
			ans = add(ans, mult(aux, inv[x]));
			d[1] = add(d[1], v[x]);
			r[1] = add(r[1], aux);
			for(ll i = 2; i*i <= x; i++){
				if(x % i == 0){
						d[i] = add(d[i], v[x]);
						r[i] = add(r[i], aux);
						if(i != x/i){
							d[x/i] = add(d[x/i], v[x]);
							r[x/i] = add(r[x/i], aux);
						}
				}
			}
	  }

		cout << ans << endl;

		forn(i, 0, mx+1){
			d[i] = r[i] = v[i] = 0;
		}

  }



}