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
int n, dp[MAX][3], inf = 1e9;
int val[MAX][3];

//top-down
int f(int i, int j){
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans = 0;
    if(i+1 == n)return ans;
    forn(k, 0, 3){
        if(k == j)continue;
        ans = max(ans, f(i+1, k)+val[i+1][k]);
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  forn(i, 0, n){
      forn(j, 0, 3){
          cin >> val[i][j];
      }
  }
  memset(dp, -1, sizeof dp);
  int ans = 0;
  forn(i, 0, 3){
      ans = max(ans, f(0, i)+val[0][i]);
  }
  cout << ans << endl;

}



