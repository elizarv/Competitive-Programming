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

const int N = 1e5+5, M = 105;
string s;
ll dp[N][M][2];
int n, D, MOD = 1e9+7;

ll f(int i, int mod, bool flag){
  if(i == n)return mod == 0;
  ll &ans = dp[i][mod][flag];
  if(ans != -1)return ans;
  ans = 0;
  int lim = flag ? 9: s[i]-'0';
  forn(j, 0, lim+1){
    int nxt_mod = (mod+j)%D;
    int nxt_flag = flag | (j < s[i]-'0');
    ans = (ans + f(i+1, nxt_mod, nxt_flag))%MOD;
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s >> D;
  n = s.size();
  memset(dp, -1, sizeof dp);
  cout << (f(0, 0, 0)-1+MOD)%MOD << endl;

}