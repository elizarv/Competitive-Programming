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


const int MAX = 10005;
vector<int> g[2][MAX];
char val[2][MAX];
int sz[MAX];
set<int> values;
int ans;

auto rnd = bind(uniform_int_distribution<ll>(100,1e18), mt19937(time(0)));

map<ll, ll> hash_node;
ll F(ll x){
    if(hash_node.count(x))return hash_node[x];
    else return hash_node[x] = rnd();
}

map<ll, ll> hash_pos;
ll G(ll x){
    if(hash_pos.count(x))return hash_pos[x];
    else return hash_pos[x] = rnd();
}

ll dfs(int u, int p, int id){
    ll sum = 0;
    int pos = 0;
    for(auto v: g[id][u]){
        if(v == p)continue;
        sum += G(pos) * F(dfs(v, u, id));
        pos++;
    }
    if(sum == 0)sum++;
    sum *= F(val[id][u]);
    ll hs = F(sum);
    if(id){
        if(values.count(hs))ans = max(ans, sz[u]);
    }else{
        values.insert(hs);
    }
    return hs;
}


void predfs(int u, int p){
    sz[u] = 1;
    for(int v: g[1][u]){
        if(v == p)continue;
        predfs(v, u);
        sz[u] += sz[v];
    }
}

void read(int n, int id){
    int p;
    forn(i, 0, n){
          cin >> val[id][i] >> p;
          if(p == -1)continue;
          g[id][p].pb(i);
          g[id][i].pb(p);
      }
}

void init(int n, int m){
    forn(i, 0, 2){
        forn(j, 0, max(n, m)+1){
            g[i][j].clear();
        }
    }
    values.clear();
    hash_node.clear();
    hash_pos.clear();
    ans = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n, m;
  cin >> t;

  while(t--){
      cin >> n >> m;
      init(n, m);
      read(n, 0);
      read(m, 1);
      predfs(0, -1);
      dfs(0, -1, 0);
      dfs(0, -1, 1);
      cout << ans << endl;
  }
  
}

