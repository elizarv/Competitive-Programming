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
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll a, b, c;
  while (cin >> a >> b >> c) {
    ll x = a*b;
    ll y = a+b*c;
    if (x < y) cout << "1\n";
    else if (x > y) cout << "2\n";
    else cout << "0\n";
  }
}
