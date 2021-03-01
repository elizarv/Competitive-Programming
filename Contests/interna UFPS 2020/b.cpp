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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t, n, k, g;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    g = (n + k - 1) / k;
    dbg(n, k, g);
    cout << k * g - n << endl;
  }
}