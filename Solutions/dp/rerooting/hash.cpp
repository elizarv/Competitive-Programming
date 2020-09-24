/*
https://www.spoj.com/problems/classical/
*/
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005, N = 20;
vector<int> g[2][MAX];
ll dp[2][MAX];
set<ll> H;
bool f;

auto rnd = bind(uniform_int_distribution<ll>(100,1e18), mt19937(time(0)));

map<ll, ll> G;
ll unhash(ll x){
    return G[x];
}

map<ll, ll> F;
ll Hash(ll x){
    if(F.count(x))return F[x];
    F[x] = rnd();
    G[F[x]] = x;
    return F[x];
}

void dfs1(int u, int p, int id){
    ll val = 1;
    for(int v: g[id][u]){
        if(v == p)continue;
        dfs1(v, u, id);
        val += dp[id][v];
    }
    dp[id][u] = Hash(val);
}

void dfs(int u, int p, int id, ll upch){
    ll val = unhash(dp[id][u]);
    val += upch;
    dp[id][u] = Hash(val);

    if(!id) H.insert(dp[id][u]);
    else if(H.count(dp[id][u])) f = true;

    for(int v: g[id][u]){
        if(v == p)continue;
        ll UP = Hash(val-dp[id][v]);
        dfs(v, u, id, UP);
    }
}



void init(int n){
    forn(i, 0, 2){
        forn(j, 0, n){
            g[i][j].clear();
            dp[i][j] = 0;
        }
    }
    H.clear();
    f = false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n, u, v;

  cin >> t;

  while(t--){
      cin >> n;
      init(n);
      forn(i, 0, 2){
          forn(j, 0, n-1){
              cin >> u >> v;
              u--, v--;
              g[i][u].pb(v);
              g[i][v].pb(u);
          }
          dfs1(0, -1, i);
          dfs(0, -1, i, 0);
      }
      if(f) cout << "YES" << endl;
      else cout << "NO" << endl;
  }
  
}