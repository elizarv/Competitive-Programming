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

const int N = 1005;
string grid[N];
ll dp[N][N];
int n, m, mod = 1e9+7;

ll f(int i, int j){
	if(i >= n || j >= m)return 0;
	if(grid[i][j] == '#')return 0;
	if(i == n-1 && j == m-1)return 1;
	ll &ans = dp[i][j];
	if(ans != -1)return ans;
	ans = 0;
	ans = (ans + f(i+1, j))%mod;
	ans = (ans + f(i, j+1))%mod;
	return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	forn(i, 0, n){
		cin >> grid[i];
	}

	memset(dp, -1, sizeof dp);
	cout << f(0, 0) << endl;

}



