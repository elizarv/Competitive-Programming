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

const int N = 20, M = 6e4;
ll dp[N][2][M][2], pot[10];
string s;
int n;

ll f(int i, bool flag, int mask, bool zero){
  if(i == n) return 1;
  ll &ans = dp[i][flag][mask][zero];
  if(ans != -1)return ans;
  ans = 0;
  int lim = flag ? 9 : s[i]-'0';
  forn(j, 0, lim+1){
    int cur = (mask / pot[j]) % 3;
    if(cur == 2)continue;
    cur++;
    int nflag = flag | (j < lim);
    int nmask = mask;
    int nzero = zero | (j);
    if(nzero) nmask += pot[j];
    ans += f(i+1, nflag, nmask, nzero);
  }
  return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("exchange.in", "r", stdin);
  freopen("exchange.out", "w", stdout);

  ll l, r;
  cin >> l >> r;
  l--;

  pot[0] = 1;
  forn(i, 1, 10){
    pot[i] = pot[i-1]*3;
  }

  s = to_string(r);
  n = s.size();
  memset(dp, -1, sizeof dp);
  ll ans = f(0, 0, 0, 0);
  s = to_string(l);
  n = s.size();
  memset(dp, -1, sizeof dp);
  ans -= f(0, 0, 0, 0);

  cout << ans << endl;

}



