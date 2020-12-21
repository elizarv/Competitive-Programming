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
int aut[MAXN][alpha];	//aut[i][j] = a donde vuelvo si estoy en i y pongo una j
 
void build(string &s){
	int lps=0;
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

string t, p;
int n, m;
vector<vector<int>> dp;

int f(int i, int cur){
	if(i == n)return (cur == m);
	int &ans = dp[i][cur];
	if(ans != -1)return ans;
	ans = 0;
	char c = t[i];
	if(c != '?'){
		int nxt = aut[cur][c - L];
		ans = max(ans, f(i+1, nxt) + (cur == m));
	}else{
		forn(ch, 0, alpha){
			int nxt = aut[cur][ch];
			ans = max(ans, f(i+1, nxt) + (cur == m));
		}
	}
	return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	cin >> t >> p;

	n = t.size();
	m = p.size();

	build(p);
	dp = vector<vector<int>>(n+2, vector<int>(m+2, -1));

	cout << f(0, 0) << endl;


} 