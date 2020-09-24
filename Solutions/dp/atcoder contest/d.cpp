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

const int N = 100005, M = 101;
int n, m;
ll dp[N][M];
const ll inf  = 1e18;
int W[N], P[N];

//top-down
ll f(int i, int w){
	if(w < 0)return -inf;
	if(i == n)return 0;
	ll &ans = dp[i][w];
	if(ans != -1)return ans;
	ans = max(f(i+1, w), f(i+1, w-W[i])+P[i]);
	return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

	forn(i, 0, n){
		cin >> W[i] >> P[i];
	}
//bottom-up
	forn(i, 0, m)dp[N-1][i] = 0;
	for(int i = n-1; i >= 0; i--){
		for(int w = 0; w <= m; w++){
			dp[i][w] = dp[i+1][w];
			if(w-W[i] >= 0) dp[i][w] = max(dp[i][w], dp[i+1][w-W[i]]+P[i]);
		}
	}

	cout << f(0, m) << endl;


  


}



