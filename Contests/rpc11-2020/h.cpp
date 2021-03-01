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

int n;
string s[3];

bool val(int i1, int i2, int k) {
  forn(i, 0, n) {
    if (s[i1][(i + k) % n] == s[i2][i]) return false;
  }
  return true;
}

void check(int i1, int i2, vector<int> &v) {
  forn(i, 0, n) {
    if (val(i1, i2, i)) v.pb(i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s[0] >> s[1] >> s[2]) {
    n = SZ(s[0]);
    vector<int> v1, v2;
    check(0, 2, v1);
    check(1, 2, v2);
    vector<bool> v3(n);
    forn(i, 0, n) { v3[i] = val(0, 1, i); }
    int p3, op1, op2, op3, ans = 1e9;
    for (int p1 : v1) {
      for (int p2 : v2) {
        if (!v3[(p1 - p2 + n) % n]) continue;
        p3 = abs(p1 - p2);
        op1 = min(p1, n - p1);
        op2 = min(p2, n - p2);
        op3 = min(p3, n - p3);
        ans = min(ans, min(op1 + op2, min(op2 + op3, op3 + op1)));
      }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
  }
}