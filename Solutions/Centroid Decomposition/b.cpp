//Solution to https://codeforces.com/contest/342/problem/E
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

const int MX = 1e5+5, LOG2 = 20, inf = 1e9;
vector<int> g[MX];
int par[MX], dep[MX], sz[MX], ans[MX];
int dist[MX][LOG2];
int n, k;

int pre(int u = 0, int p = 0) {
    sz[u] = 1;
    for (auto &v : g[u]) 
        if (!dep[v] && v != p) 
            sz[u] += pre(v, u);
    return sz[u];
}

int centroid(int u, int p, int k) {
    for (auto &v : g[u]) 
        if (!dep[v] && v != p && sz[v] > k) 
            return centroid(v, u, k);
    return u;
}

void dfs(int u, int p, int d, int lvl){
    dist[u][lvl] = d;
    for(int &v: g[u]){
        if(v == p || dep[v])continue;
        dfs(v, u, d+1, lvl);
    }
}

void build(int u = 0, int p = -1, int d = 1) {
    int k = pre(u, p);
    int c = centroid(u, p, k/2);
    par[c] = p; dep[c] = d;
    dfs(c, p, 0, d);
    for (auto &v : g[c]) 
        if (!dep[v]) build(v, c, d+1);
}

int getdist(int u, int v, int lvl){
    return dist[u][lvl] + dist[v][lvl];
}

void update(int u){
    int a = u;
    while(a != -1){
        ans[a] = min(ans[a], getdist(a, u, dep[a]));
        a = par[a];
    }
}

int query(int u){
    int a = u;
    int r = inf;
    while(a != -1){
        r = min(r, ans[a] + getdist(u, a, dep[a]));
        a = par[a];
    }
    return r;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    int m;
	cin >> n >> m;
    forn(i, 1, n){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    forn(i, 0, n+1){
        ans[i] = inf;
    }
    build();
    update(0);

    forn(i, 0, m){
        int t, x;
        cin >> t >> x;
        x--;
        if(t == 1){
            update(x);
        }else{
            cout << query(x) << endl;
        }
    }

  
}