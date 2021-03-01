#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5;
vector<pair<char, int>> g[N];
int dist[N], par[N];

struct edge {
    int v, d;
    char c;

    bool operator < (const edge &x) const {
      if(d == x.d)return c > x.c;
      return d > x.d;
    }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  

  int n, m;
  cin >> n >> m;
  forn(i, 0, m){
    int u, v;
    char c;
    cin >> u >> v >> c;
    u--, v--;
    g[u].pb({c, v});
    g[v].pb({c, u});
  }

  queue<int> q;
  memset(dist, -1, sizeof dist);
  dist[n-1] = 0;
  q.push(n-1);

  while(q.size()){
    int u = q.front();
    q.pop();
    for(auto &nx: g[u]){
      int v = nx.S;
      if(dist[v] == -1 || dist[v] > dist[u]+1){
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }

  cout << dist[0] << endl;

  vector<int> cur = {0};
  string p;
  while(cur.size()){
    char mn = 'z'+1;
    set<int> temp;
    for(auto &u: cur){
      for(auto &nx: g[u]){
        int v = nx.S;
        char c = nx.F;
        if(dist[v]+1 == dist[u]){
          if(c <= mn){
            if(c < mn)temp.clear();
            mn = c;
            temp.insert(v);
            par[v] = u;
          }
        }
      }
    }
    if(mn < 'z'+1)p.pb(mn);
    cur.clear();
    for(auto &x: temp){
      cur.pb(x);
    }
  }

  int u = n-1;
  vector<int> ans;
  ans.pb(n);
  while(u != 0){
    ans.pb(par[u]+1);
    u = par[u];
  }

  reverse(ans.begin(), ans.end());

  forn(i, 0, ans.size()){
    int x = ans[i];
    cout << x << " \n"[i+1 == ans.size()];
  }

  cout << p << endl;


  

}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/