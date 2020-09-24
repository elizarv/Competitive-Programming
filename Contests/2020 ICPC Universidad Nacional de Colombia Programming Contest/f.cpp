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
    int v, k, w;
    bool operator < (const edge &b) const {
        return w > b.w;
    }
};

const int N = 1e4+2, K = 15, inf = 1e9;
vector<pii> g[2][N];
int dist[2][2][N][K], a, b, k;
//[person][dir][u][k]

void dijkstra(bool f, bool dir){
    priority_queue<edge> pq;
    int u = a, t = b;
    if(f)swap(u, t);
    forn(i, 0, k+1){
        pq.push({u, i, 0});
        dist[f][dir][u][i] = 0;
    }

    while(pq.size()){
        u = pq.top().v;
        int it = pq.top().k;
        pq.pop();
        if(dist[f][dir][u][it] != inf)continue;
        for(auto nx: g[dir][u]){
            int v = nx.F;
            int w = nx.S;
            if(dist[f][dir][v][it] > dist[f][dir][u][it]+w){
                dist[f][dir][v][it] = dist[f][dir][u][it]+w;
                pq.push({v, it, dist[f][dir][v][it]});
            }
            if(it && dist[f][dir][v][it-1] > dist[f][dir][u][it]){
                dist[f][dir][v][it-1] = dist[f][dir][u][it];
                pq.push({v, it-1, dist[f][dir][v][it-1]});
            }
        }
    }


}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
  cin >> a >> b >> k;
  int u, v, w;
  forn(i, 0, m){
      cin >> u >> v >> w;
      g[0][u].pb({v, w});
      g[1][v].pb({u, w});
  }
  forn(i, 0, 2){
      forn(j, 0, 2){
          forn(u, 0, n+1){
              forn(v, 0, k+1)dist[i][j][u][v] = inf;
          }
      }
  }
  forn(i, 0, 2){
      forn(j, 0, 2)dijkstra(i, j);
  }
  int ans = 1e9, node = -1;
  forn(x, 0, n){
      if(x == a || x == b)continue;
      int mna = 1e9, mnb = 1e9;
      forn(it, 0, k+1){
        mna = min(mna, dist[0][0][x][it]+dist[0][1][x][k-it]);
        mnb = min(mnb, dist[1][0][x][it]+dist[1][1][x][k-it]);
      }
      if(ans > mna+mnb){
				ans = mna+mnb;
				node = x;
			}
  }

	if(ans == inf)cout << ">:(" << endl;
  else cout << node << " " << ans << endl;

  
}