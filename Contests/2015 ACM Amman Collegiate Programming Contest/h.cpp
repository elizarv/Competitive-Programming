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

struct edge {
    int u, v, comp;
    bool bridge;
};

const int MX = 1e5+5;
vector<int> g[MX];
vector<edge> e;
stack<int> st;
int low[MX], num[MX], cont;
bool art[MX];
int BCC, bg;
int n, m;

void add_edge(int u, int v){
    g[u].push_back(e.size());
    g[v].push_back(e.size());
    e.push_back({u, v, -1, false});
}

void dfs(int u, int p = -1) {
    low[u] = num[u] = cont++;
    for (auto &i : g[u]) {
        edge &ed = e[i];
        int v = ed.u^ed.v^u;
        if (num[v] == -1) {
            st.push(i);
            dfs(v, i);
            if (low[v] > num[u]){
                ed.bridge = true;
                bg++;
            }
            if (low[v] >= num[u]) {
                art[u] = (num[u] > 0 || num[v] > 1); 
                int last; 
                do {
                    last = st.top(); st.pop();
                    e[last].comp = BCC;
                } while (last != i);
                BCC++;
            }
            low[u] = min(low[u], low[v]);
        } else if (i != p && num[v] < num[u]) {
            st.push(i);
            low[u] = min(low[u], num[v]);
        }
    }
}


int dis[MX];

void init() {
    cont = BCC = bg = 0;
    e.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        num[i] = -1;
        art[i] = false;
        dis[i] = -1;
    }
}


void dfs2(int u, int p, int d){
  dis[u] = d;
  for(auto &i: g[u]){
    edge &ed = e[i];
    int v = u^ed.u^ed.v;
    if(v == p || dis[v] != -1)continue;
    dfs2(v, u, d+ed.bridge);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    init();
    forn(i, 0, m){
      int u, v;
      cin >> u >> v;
      u--, v--;
      add_edge(u, v);
    }

    dfs(0);

    dfs2(0, -1, 0);
    int mx = 0, id = 0;
    forn(i, 0, n){
      if(dis[i] > mx){
        mx = dis[i];
        id = i;
      }
    }
    memset(dis, -1, sizeof dis);
    dfs2(id, -1, 0);
    mx = 0;
    forn(i, 0, n){
      mx = max(mx, dis[i]);
    }
    cout << bg - mx << endl;
  }
  
}