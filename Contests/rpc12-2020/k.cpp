#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int MX = 2e6;
  vector<int> prime(MX, true);
  prime[0] = prime[1] = false;
  vector<int> primes;
  for (int i = 2; i <= MX; ++i) {
    if (prime[i]) {
      primes.pb(i);
      for (ll j = 1ll*i*i; j <= MX; j += i) {
        prime[j] = false;
      }
    }
  }

  ll a, b, k;
  while (cin >> a >> b >> k) {

    vector<bool> f(b-a+1, false);
    ll ans = 0;

    for (auto &p : primes) {
      for (ll j = (a+p-1)/p * p; j <= b; j += p) {
        if (f[j-a]) continue;
        f[j-a] = true;
        ans += p;
        k--;
        if (!k) break;
      }
      if (!k) break;
    }
    cout << ans << endl;
  }
}
