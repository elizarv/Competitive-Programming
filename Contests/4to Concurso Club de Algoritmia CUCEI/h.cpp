#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7, N = 1e4+5;
int fact[N], cal[N], inv[N];
vector<pair<int, pii>> qu[N];

int add(ll a, ll b){
  if( a + b < MOD)return a + b;
  return a + b - MOD;
}

int mult(ll a, ll b){
  if(a * b < MOD)return a * b;
  return (a*b)%MOD;
}

int subs(ll a, ll b){
  if(a - b >= 0) return a - b;
  return a - b + MOD;
}


int expmod(int b, int e, int m = MOD) {
    int ans = 1;
    while (e) {
        if (e&1) ans = mult(ans, b);
        b = mult(b, b);
        e /= 2;
    }
    return ans;
}

int invmod(int a, int m = MOD) {
    return expmod(a, m-2, m);
}

void pre(){
  fact[0] = 1;
  inv[0] = invmod(fact[0]);
  forn(i, 1, N){
    fact[i] = mult(fact[i-1], i);
    inv[i] = invmod(fact[i]);
  }
}


int cm(int n, int i){
  int ans = fact[n];
  ans = mult(ans, inv[i]);
  ans = mult(ans, inv[n-i]);
  return ans;
}

void f(int n){
  cal[0] = 1;
  forn(i, 1, n+1){
    cal[i] = cm(n, i);
    cal[i] = add(cal[i], cal[i-1]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  pre();

  int t;
  cin >> t;

  int lim = 0;

  forn(i, 0, t){
    int n, a, b;
    cin >> n >> a >> b;
    qu[n].pb({i, {a, b}});
    lim = max(n, lim);
  }

  vector<int> ans(t);

  forn(n, 0, lim+1){
    if(!qu[n].size())continue;
    f(n);
    for(auto x: qu[n]){
      int a = x.S.F;
      int b = min(x.S.S, n);
      ans[x.F] = a > b ? 0 : subs(cal[b], cal[a-1]);
    }
  }

  for(auto x: ans){
    cout << x << endl;
  }

  
}