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

const int MAX = 100005;
int H[MAX], n, dp[MAX], inf = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int K;
  cin >> n >> K;
  forn(i, 0, n)cin >> H[i];
  fill(dp, dp+n, inf);
  //bottom-up
  dp[n-1] = 0;
  for(int i = n-1; i >= 0; i--){
      forn(k, 1, K+1){
				if(i-k >= 0)dp[i-k] = min(dp[i-k], dp[i]+abs(H[i]-H[i-k]));
      }
  }
  cout << dp[0] << endl;

}



