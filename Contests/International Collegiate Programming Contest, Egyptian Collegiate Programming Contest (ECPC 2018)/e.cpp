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

const int inf = 1e9, MOD = 1e9+7;
const int MX = 205;
int dp[MX][MX][2][MX][2]; // menores, mayores, mayor?, tam, k?
int K;

int add(ll a, ll b){
	if(a + b < MOD)return a + b;
	return a + b - MOD;
}

int f(int mn, int my, bool wmay, int tam, bool k){
	if(!mn && !my && wmay) return k;
	int &ans = dp[mn][my][wmay][tam][k];
	if(ans != -1)return ans;
	ans = 0;
	if(wmay){ // quiero uno mayor
		if(my){
			if(tam+1 <= K){
				ans = add(ans, f(mn, my-1, true, tam+1, k || tam+1 == K)); // tomarlo y seguir con mayores
				ans = add(ans, f(mn, my-1, false, 0, k || tam+1 == K)); // tomarlo y terminar
			}
			ans = add(ans, f(mn+1, my-1, true, tam, k)); // no tomarlo seguir con mayores
		}
	}else{
		if(mn){
			ans = add(ans, f(mn-1, my, false, 0, k || K == 1)); // tomarlo y seguir con menor
			ans = add(ans, f(mn-1, my+1, false, 0, k)); // no tomarlo y seguir con menores
			ans = add(ans, f(mn-1, my, true, 1, k || K == 1)); // tomarlo y seguir con mayores
		}
	}
	return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
//   freopen("permutations.in", "r" , stdin);

	int t; cin >> t;

	while(t--){
		int n;
		cin >> n >> K;

		memset(dp, -1, sizeof dp);

		cout << f(0, n, 1, 0, 0) << endl;

	}
  
  
  
}