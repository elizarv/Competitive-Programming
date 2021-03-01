//Solution to https://codeforces.com/contest/161/problem/D
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

const int MX = 5e4+5, K = 505;
vector<int> g[MX];
int par[MX], dep[MX], sz[MX];
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

ll dis[K], ans;

void sum(int u, int p, int d){
    if(k-d >= 0)ans += dis[k-d];
    for(int &v: g[u]){
        if(v == p || dep[v])continue;
        sum(v, u, d+1);
    }
}

void dfs(int u, int p, int d){
    if(d <= k)dis[d]++;
    for(int &v: g[u]){
        if(v == p || dep[v])continue;
        dfs(v, u, d+1);
    }
}

void go(int u, int p){
    memset(dis, 0, sizeof dis);
    for(int &v: g[u]){
        if(v == p || dep[v])continue;
        sum(v, u, 1);
        dfs(v, u, 1);
    }
    ans += dis[k];
}

void build(int u = 0, int p = -1, int d = 1) {
    int k = pre(u, p);
    int c = centroid(u, p, k/2);
    par[c] = p; dep[c] = d;
    go(c, p);
    for (auto &v : g[c]) 
        if (!dep[v]) build(v, c, d+1);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
    forn(i, 1, n){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    build();
    cout << ans << endl;

  
}