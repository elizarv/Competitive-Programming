#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<ll, ll> pii;

struct edge {
    int u, v, comp; //A que componente biconexa pertenece
    bool bridge; //Si la arista es un puente
};

const int MX = 1e5+5; //Cantidad maxima de nodos
vector<int> g[MX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
stack<int> st;
int low[MX], num[MX], cont;
bool art[MX]; //Si el nodo es un punto de articulacion
vector<set<int>> comps; //Componentes biconexas
vector<vector<int>> tree; //Block cut tree
vector<int> id; //Id del nodo en el block cut tree
int BCC; //Cantidad de componentes biconexas
int n, m; //Cantidad de nodos y aristas

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
            if (low[v] > num[u])
                ed.bridge = true; //bridge
            if (low[v] >= num[u]) {
                art[u] = (num[u] > 0 || num[v] > 1); //articulation
                int last; //start biconnected
                comps.push_back({});
                do {
                    last = st.top(); st.pop();
                    e[last].comp = BCC;
                    comps.back().insert(e[last].u);
                    comps.back().insert(e[last].v);
                } while (last != i);
                BCC++; //end biconnected
            }
            low[u] = min(low[u], low[v]);
        } else if (i != p && num[v] < num[u]) {
            st.push(i);
            low[u] = min(low[u], num[v]);
        }
    }
}

int ans;

void init() {
    cont = BCC = 0;
    comps.clear();
    e.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        num[i] = -1; //no visitado
        art[i] = false;
    }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  init();
  forn(i, 0, m){
    int u, v;
    cin >> u >> v;
    u--, v--;
    add_edge(u, v);
  }

  dfs(0);
  ans = 0;
  for (auto &comp : comps) {
      ans = max(ans, (int)comp.size());
  }

  cout << ans << endl;

}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/