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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55, K = N * N, INF = 1e9;
int n, k;
vector<ll> dis[K];
vector<pii> x[K];

int dist(pii a, pii b) { return abs(a.F - b.F) + abs(a.S - b.S); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int _k;

  cin >> n >> k;

  forn(i, 0, n) {
    forn(j, 0, n) {
      cin >> _k;
      x[_k - 1].pb({i, j});
    }
  }

  dis[0].resize(SZ(x[0]), 0);

  bool cond = 1;

  forn(i, 1, k) {
    cond = SZ(x[i]) > 0;
    if (!cond) break;
    dis[i].resize(SZ(x[i]), INF);
    forn(u, 0, SZ(x[i - 1])) {
      forn(v, 0, SZ(x[i])) {
        dis[i][v] = min(dis[i][v], dis[i - 1][u] + dist(x[i - 1][u], x[i][v]));
      }
    }
  }

  if (!cond) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = *min_element(dis[k - 1].begin(), dis[k - 1].end());
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}