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

const int N = 305, M = 105, mod = 1e9+7;
int dp[M][M][M];
string s, t, p, q;

int add(ll a, ll b){
	if(a + b < mod)return a+b;
	return a + b - mod;
}

int f(int i, int a, int b, int c){
	if(i == s.size())return 1;
	int &ans = dp[a][b][c];
	if(ans != -1)return ans;
	ans = 0;
	if(a < t.size() && s[i] == t[a])ans = add(ans, f(i+1, a+1, b, c));
	if(b < p.size() && s[i] == p[b])ans = add(ans, f(i+1, a, b+1, c));
	if(c < q.size() && s[i] == q[c])ans = add(ans, f(i+1, a, b, c+1));
	return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> t >> p >> q >> s;
	memset(dp, -1, sizeof dp);
  cout << f(0, 0, 0, 0) << endl;



}