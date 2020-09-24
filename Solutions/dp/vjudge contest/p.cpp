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

const int N = 130, M = 1000, MOD  = 1e9 + 9;
int dp[N][M][N], n, m;
int pot[N];

int add(int a, int b, int m){
  if(1ll*a+b >= m) return 1ll*a+b-m;
  else return 1ll*a+b;
}

int f(int i, int mod, int cnt){
  if(i < 0){
    if(!mod)return cnt;
    return 0;
  }
  int &ans = dp[i][mod][cnt];
  if(ans != -1)return ans;
  ans = 0;
  ans = add(ans, f(i-1, add(pot[i],mod, n), cnt+1), MOD); // encendido
  ans = add(ans, f(i-1, mod, cnt), MOD);//apagado
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  pot[0] = 1;
  forn(i, 1, m){
    pot[i] = (1ll*pot[i-1]*2) % n;
  }
  memset(dp, -1, sizeof dp);
  int ans = f(m-1, 0, 0);
  if(!pot[m])ans = add(ans, 1, MOD);
  ans = (1ll*ans-1+MOD) % MOD;
  cout << ans << endl;




}



