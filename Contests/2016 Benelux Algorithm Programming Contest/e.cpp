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

struct edge {
  int v;
  ll w;

  bool operator < (const edge & b) const{
    return w > b.w;
  }
};

const int MX = 1e4+5;
const ll inf = 1e18;
vector<edge> g[MX];
ll dist[MX];
int n, m, x;

ll dijkstra(ll mx){
  priority_queue<edge> pq;
  forn(i, 0, n+1)dist[i] = inf;
  dist[0] = 0;
  pq.push({0, 0});

  while(pq.size()){
    int u = pq.top().v;
    ll w = pq.top().w;
    pq.pop();
    if(dist[u] != w)continue;
    if(u == n-1)return dist[n-1];
    for(auto &nx: g[u]){
      int v = nx.v;
      if(nx.w > mx)continue;
      if(dist[v] == inf || dist[v] > dist[u]+nx.w){
        dist[v] = dist[u]+nx.w;
        pq.push({v, dist[v]});
      }
    }
  }
  return inf;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> m >> x;
  int u, v, w;
  int r = 0;
  forn(i, 0, m){
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
    r = max(r, w+1);
  }

  ll mn = dijkstra(inf);
  mn += (mn * x)/100;

  int l = 1;
  while(l < r){
    m = (l+r)/2;
    if(dijkstra(m) <= mn)r = m;
    else l = m+1;
  }

  cout << l << endl;


}