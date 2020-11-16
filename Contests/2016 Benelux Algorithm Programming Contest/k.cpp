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

const int MOD = 123456789;

int add(ll a, ll b){
	if(a + b < MOD)return a + b;
	return a + b - MOD;
}

int mult(ll a, ll b){
	return (a * b) % MOD;
}

int subs(ll a, ll b){
	if(a - b >= 0)return a - b;
	return a - b + MOD;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int l, s;
  cin >> l >> s;

	vector<int> dp(l+1, 0);

	int ans = 0;
	dp[0] = 1;

	int pot = 1;
	
  forn(i, 0, s){// 2^i -1
		dp[i] = subs(mult(2, pot), 1);
		pot = mult(2, pot);
		ans = add(ans, dp[i]);
  }

	forn(i, s, l){
		dp[i] = ans;
		ans = add(ans, subs(dp[i], dp[i-s]));
	}

	cout << dp[l-1] << endl;
  

  
}