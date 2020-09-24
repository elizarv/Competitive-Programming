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

const int N = 1000005, M = 101;
int n, m;
int dp[M][N];
const int inf  = 1e9+5;
int W[M], P[M], r;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

	forn(i, 1, n+1){
		cin >> W[i] >> P[i];
	}

	int ans = 0;
	//bottom-up
	forn(i, 0, n+1){
		forn(j, 0, N){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	forn(i, 1, n+1){
		for(int j = N-P[i]; j >= 0; j--){
			dp[i][j] = dp[i-1][j];
			if(j+P[i] < N){
				int &ans = dp[i][j+P[i]];
				ans = min(ans, dp[i-1][j+P[i]]);
				ans = min(ans, dp[i-1][j]+W[i]);
			}
		}
	}
	forn(i, 0, N)if(dp[n][i] <= m)ans = max(ans, i);
	cout << ans << endl;


}



