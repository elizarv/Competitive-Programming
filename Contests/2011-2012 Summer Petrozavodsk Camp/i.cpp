//Solutions to contest: https://codeforces.com/gym/100492
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

const int N = 2 * 1e5 + 1;
int n, m;
map<int, int> g[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp
  // ./main < main.txt
  freopen("intouch.in", "r", stdin);
  freopen("intouch.out", "w", stdout);
  cin >> n >> m;
  vector<int> p, ans;
  p = ans = vector<int>(n, 0);
  char c;
  int u, v;
  while (m--) {
    cin >> c;
    if (c == '!') {
      cin >> u;
      p[u - 1]++;
    } else if (c == '+') {
      cin >> u >> v;
      u--, v--;
      g[u][v] = 1;
      g[v][u] = 1;
      ans[u] -= p[v];
      ans[v] -= p[u];
    } else {
      cin >> u >> v;
      u--, v--;
      g[u].erase(v);
      g[v].erase(u);
      ans[u] += p[v];
      ans[v] += p[u];
    } 
  }
  for (int i = 0; i < n; i++) {
    for (auto x: g[i]) {
      u = i, v = x.F;
      ans[v] += p[u];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i + 1 == n];
  }
}