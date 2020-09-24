//https://codeforces.com/gym/102411
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

const int MX = 2e5+5, inf = 1e9;
vector<int> g[MX];
int cnt[MX], dist[MX], n, m;
bitset<MX> marked, vis;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int u, v;
  cin >> n >> m;

  forn(i, 0, n-1){
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  queue<pii> q;

  forn(i, 0, m){
    cin >> u;
    u--;
    marked[u] = true;
    cnt[u] = vis[u] = 1;
    q.push({u, -1});
  }

  int center;
  bool f = false;

  if(m == 1){
    f = true;
    center = u;
  }

  while(q.size()){
    u = q.front().F;
    int p = q.front().S;
    q.pop();
    for(auto v: g[u]){
      if(!vis[v]){
        vis[v] = true;
        q.push({v, u});
      }
      if(v != p && !marked[v]){
        cnt[v] += cnt[u];
        if(cnt[v] == m){
          f = true;
          center = v;
        }
      }
    }
  }
    if(f){
      cout << "YES " << endl;
      cout << center+1;
    }else cout << "NO";
    cout << endl;


}