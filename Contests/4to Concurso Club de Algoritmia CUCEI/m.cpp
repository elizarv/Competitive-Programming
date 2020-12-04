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

void fact(ll n, map<ll, int> &f) {
    for (int p = 2; 1ll*p*p <= n; p++)
        while (n%p == 0) f[p]++, n /= p;
    if (n > 1) f[n]++;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	ll n, m;
	cin >> n >> m;

	map<ll, int>f;
	fact(m, f);
	ll ans = 1;
	for(auto x: f){
		if(x.S >= n){
			forn(i, 0, x.S/n){
				ans *= x.F;
			}
		}
	}

	cout << ans << endl;
	

  
  
}