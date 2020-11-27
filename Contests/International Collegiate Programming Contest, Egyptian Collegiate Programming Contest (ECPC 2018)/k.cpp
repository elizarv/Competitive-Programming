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

const int MAXN=1e5+5, alpha=26;
const char L = 'a';
int aut[MAXN][alpha];

 
void build(string &s){
	int lps=0;
	forn(i, 0, alpha)aut[0][i] = 0;
	aut[0][s[0]-L] = 1;
  int n = s.size();
	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < alpha; j++) aut[i][j] = aut[lps][j];
		if(i < n){
			aut[i][s[i]-L] = i+1;
			lps = aut[lps][s[i]-L];
		}
	}
}

const int MAXM = 105;
ll pre[MAXN][MAXM];
ll suf[MAXN][MAXM];
ll acum[MAXN][MAXM];
ll dp[MAXN][MAXM];


string s,p;
int n, m;

ll f(int i, int j){
	if(i == n)return 0;
	ll &ans = dp[i][j];
	if(ans != -1)return ans;
	int c = s[i] - L;
	int nxt = aut[j][c];
	ans = f(i+1, nxt) + (nxt == m);
	return ans;
}


ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a%b);
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("string.in", "r" , stdin);

	int t;
	cin >> t;
	while(t--){
		cin >> s >> p;
		n = s.size();
		m = p.size();

		forn(i, 0, n+2){
			forn(j, 0, m+1){
				dp[i][j] = -1;
				pre[i][j] = suf[i][j] = acum[i][j] = 0;
			}
		}

		build(p);

		int j = 0;
		forn(i, 0, n){
			int c = s[i]-L;
			int nxt = aut[j][c];
			pre[i][nxt] = nxt == m;
			acum[i][nxt] = 1;
			if(i)pre[i][nxt] += pre[i-1][j];
			j = nxt;
		}

		forn(i, 1, n){
			forn(j, 0, m+1){
				pre[i][j] += pre[i-1][j];
				acum[i][j] += acum[i-1][j];
			}
		}

		for(int i = n; i >= 0; i--){
			forn(j, 0, m+1){
				suf[i][j] = suf[i+1][j] + 1ll*f(i, j);
			}
		}
   
		int q;
		cin >> q;
		while(q--){
			int a, b;
			cin >> a >> b;
			a--, b--;
			ll ans = 0;
			forn(i, 0, m+1){
				ans += pre[a][i]*(n-b) + suf[b][i]*acum[a][i];
			}
			ll den = 1ll*(a+1)*(n-b);
			ll g = gcd(ans, den);
			ans /= g;
			den /= g;
			cout << ans << "/" << den << endl;
		}

	}

  
  
}