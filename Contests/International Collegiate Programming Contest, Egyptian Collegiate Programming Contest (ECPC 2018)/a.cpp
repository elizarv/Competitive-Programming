//Solutions to contest https://codeforces.com/gym/101992
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

const int N = 45;
vector<int> M[N];

void init(){
	forn(i, 0, N){
		M[i].clear();
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("zeros.in", "r" , stdin);

  int t;
  cin >> t;
  while(t--){
		int x, y, mod, k, n;
		cin >> x >> y >> mod >> k;

		n = x+y;
		init();

		int a = n/2 + 1;
		int b = n-a;

		for(ll mask = 0; mask < (1ll << a); mask++){
			if(!(mask >> (a-1) & 1))continue;
			int ones = __builtin_popcount(mask);
			if(ones > x)continue;
			ll aux = (mask << b);
			int m1 = aux % mod;
			M[ones].pb(m1);
		}

		forn(i, 0, N){
			sort(M[i].begin(), M[i].end());
		}

		ll ans = 0;

		for(ll mask = 0; mask < (1ll << b); mask++){
			int ones = __builtin_popcount(mask);
			if(ones > x)continue;
			int rest = x - ones;
			int m2 = mask % mod;
			int l, r;
			if (m2 <= k) {
				l = lower_bound(M[rest].begin(), M[rest].end(), k - m2) - M[rest].begin();
				r = lower_bound(M[rest].begin(), M[rest].end(), mod - m2) - M[rest].begin();
				ans += r-l;
			} else {
				l = lower_bound(M[rest].begin(), M[rest].end(), mod - m2) - M[rest].begin();
				ans += l;
				r = lower_bound(M[rest].begin(), M[rest].end(), mod + k - m2) - M[rest].begin();
				ans += M[rest].size()-r;
			}
		}

		cout << ans << endl;

  }

}