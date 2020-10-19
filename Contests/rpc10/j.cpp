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

const int N = 60, M = 3000;
int n, m;
ll dp[N][N][M];

ll f(int i, int j, int k){
	if(i == n)return k == m;
	ll &ans = dp[i][j][k];
	if(ans != -1)return ans;
	ans = 0;
	if(k+j <= m)ans += f(i+1, j, k+j);
	ans += f(i+1, j+1, k);
	return ans;
}

void build(int i, int j, int k, ll pos, string& s){
	if(i == n)return;
	if(k+j <= m && pos <= f(i+1, j, k+j)){
		s.pb('A');
		build(i+1, j, k+j, pos, s);
		return;
	}
	pos -= f(i+1, j, k+j);
	s.pb('B');
	build(i+1, j+1, k, pos, s);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	memset(dp, -1, sizeof dp);
	ll cnt = f(0, 0, 0);
	if(cnt&1){
		string s = "";
		build(0, 0, 0, cnt/2+1, s);
		cout << s << endl;
	}else{
		string s = "";
		build(0, 0, 0, cnt/2, s);
		cout << s << endl;
		s = "";
		build(0, 0, 0, cnt/2+1, s);
		cout << s << endl;
	}



}