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

const int N = 1e5 + 10;
int n, a[N], b[N], ans;

void dfs (int u) {
  if (a[u] == 0) return;
  ans++;
  dfs(a[u]);
  a[u] = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  forn (i, 1, n + 1) cin >> a[i];
  forn (i, 1, n + 1) cin >> b[i];
  ans = 0;
  forn (i, 1, n + 1) {
    if (a[i] != b[i]) dfs(i);
  }
  forn (i, 1, n + 1) {
    if (a[i] != b[i]) {
      ans++;
      dfs(b[i]);
    }
  }
  cout << ans << endl;
}