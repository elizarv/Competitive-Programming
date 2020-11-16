#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
  vector<int> par, sz;
  int cnt;
  ll ans;

  DSU(int n) {
    par = vector<int>(n);
    sz = vector<int>(n, 1);
    cnt = n;
    ans = n;
    forn(i, 0, n) { par[i] = i; }
  }

  int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }

  void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[v] > sz[u]) swap(v, u);
    par[v] = u;
    ans -= 1ll * sz[u] * sz[u];
    ans -= 1ll * sz[v] * sz[v];
    sz[u] += sz[v];
    ans += 1ll * sz[u] * sz[u];
    cnt--;
  }

  void getAns() {
    ll g = __gcd(ans, (ll)cnt);
    ll aux = ans;
    int auxcnt = cnt;
    aux /= g;
    auxcnt /= g;
    cout << aux << "/" << auxcnt << endl;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  forn(i, 0, m) {
    int t;
    cin >> t;
    if (t == 2) {
      dsu.getAns();
    } else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      dsu.unite(u, v);
    }
  }
}
