#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 1e5 + 10;
int n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> rep, prefix;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += SZ(rep) - prefix[a[i]];
    prefix[a[i]] = SZ(rep);
    rep[a[i]]++;
  }
  cout << ans << endl;
  return 0;
}
