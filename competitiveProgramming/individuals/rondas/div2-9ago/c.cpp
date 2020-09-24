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

int mod = 1e9+7;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<int> fac(n+1, 1);
	forn(i, 1, n+1){
		fac[i] = (fac[i-1]*i)%mod;
	}
	int p = n-2;
	ll ans = 0;
	forn(i, 1, n-1){
		int gr = n-i;
		ll aux = (gr*(n-gr))%mod;
		aux = (aux*p)%mod;
		ans = (ans+aux)%mod;
	}
	cout << ans << endl;
  
}

