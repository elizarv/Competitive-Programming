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

const int MOD = 1e9 + 7;

int pow(int b, int e, int m) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

int invmod(int a, int m = MOD) {
    return pow(a, m-2, m);
}

int add(int a, int b){
	if(a+b > MOD)return a+b-MOD;
	return a+b;
}

int sum(ll n){
	return (n*add(n,1) % MOD)*invmod(2) % MOD;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
	  ll n;
	  cin >> n;
	  if(n == 1){
		  cout << 1 << endl;
		  continue;
	  }
	  if(n == 2){
		  cout << 5 << endl;
		  continue;
	  }
	  ll side = (n+1)/2;
	  ll side2 = 1ll*side + !(n&1);
	  int last = sum(n);
	  int first = sum(n-side)+1;
	  int cur = add(first, last);

	  debug(n, first, last, cur);

	  side %= MOD;
	  side2 %=MOD;
	  
	  ll ans = (cur*area) % MOD;

	  cout << ans << endl;

  }

  
}



