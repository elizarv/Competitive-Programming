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

const int N = 100005;
string S[N][2];
int val[N], n;
ll dp[N][2], inf = 1e18;

ll f(int i, int j){
	if(i+1 == n)return 0;
	ll &ans = dp[i][j];
	if(ans != -1)return ans;
	ans = inf;
	if(i+1 < n && S[i][j] <= S[i+1][0])ans = min(ans, f(i+1, 0));
	if(i+1 < n && S[i][j] <= S[i+1][1])ans = min(ans, f(i+1, 1)+val[i+1]);
	return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  forn(i, 0, n)cin >> val[i];

	string s;
  forn(i, 0, n){
		cin >> s;
		S[i][0] = S[i][1] = s;
		reverse(S[i][1].begin(), S[i][1].end());
	}
	memset(dp, -1, sizeof dp);
	ll ans = min(f(0, 0), f(0, 1)+val[0]);

	if(ans == inf)cout << "-1"<< endl;
	else cout << ans << endl;
    
  
}

