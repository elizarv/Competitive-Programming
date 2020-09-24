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

const int N = 3005;
int A[N];
ll dp[N][N];

ll f(int i, int j){
  if(i > j)return 0;
  ll &ans = dp[i][j];
  if(ans != -1)return ans;
  ans = 0;
  ans = max(A[i]-f(i+1, j), A[j]-f(i, j-1));
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll tot = 0;
  cin >> n;
  forn(i, 0, n){
    cin >> A[i];
    tot += A[i];
  }
  memset(dp, -1, sizeof dp);
  ll ans = f(0, n-1);
  cout << ans << endl;


}



