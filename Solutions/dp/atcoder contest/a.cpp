/*
Solutions to the contest: https://atcoder.jp/contests/dp/tasks
*/

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

//top-down
int f(int i){
    if(i == n-1)return 0;
    int &ans = dp[i];
    if(ans != -1)return ans;
    ans = inf;
    if(i+1 < n)ans = min(ans, f(i+1)+abs(H[i]-H[i+1]));
    if(i+2 < n)ans = min(ans, f(i+2)+abs(H[i]-H[i+2]));
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  forn(i, 0, n)cin >> H[i];
  memset(dp, -1, sizeof dp);
  //bottom-up
  dp[n-1] = 0;
  for(int i = n-1; i >= 0; i--){
      if(i-1 >= 0)dp[i-1] = min(dp[i-1], dp[i]+abs(H[i]-H[i-1]));
      if(i-2 >= 0)dp[i-2] = min(dp[i-2], dp[i]+abs(H[i]-H[i-2]));
  }
  cout << f(0) << endl;

}



