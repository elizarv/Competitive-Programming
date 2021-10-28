#include <bits/stdc++.h>
using namespace std;
void print() {cout<<endl;}
template<typename T,typename... E>
void print(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");print(e...);}
#define forn(i,x,n) for(int i=int(x);i<int(n);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18+1;
vector<vector<ll>> dp;
vector<vector<int>> g;
vector<ll> tmp;
vector<int> sz;
int n;

ll add(ll a, ll b) {
    if (a >= inf-b) return inf;
    return a+b;
}

ll mul(ll a, ll b) {
    if (a >= inf/b) return inf;
    return a*b; 
}

void go(int u, int p = -1) {
    dp[u][1] = sz[u] = 1;
    for (auto &v : g[u]) {
        if (v == p) continue;
        go(v, u);
        int m = sz[u]+sz[v]+1;
        tmp.assign(m, 0);
        forn(i, 1, sz[u]+1) {
            forn(j, 1, sz[v]+1) {
                tmp[i+j] = add(tmp[i+j], mul(dp[u][i], dp[v][j]));
            }
        }
        forn(i, 1, m) dp[u][i] = add(dp[u][i], tmp[i]);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll k;
    cin >> n >> k;
    g.assign(n, {});
    forn(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    sz.assign(n, 0);
    dp.assign(n, vector<ll>(n+1, 0));
    go(0);
    
    int ans = -1;
    forn(j, 1, n+1) {
        forn(i, 0, n) {
            k -= dp[i][j];
            if (k <= 0) {
                ans = j;
                break;
            }
        }
        if (ans != -1) break;
    }
    
    cout << ans << endl;
}
