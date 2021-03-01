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

const int N = 2e5+5;
vector<int> P, Q;
int n, p, q, s;

bool f(int d){
    multiset<int> ms(Q.begin(), Q.end());
    int ans = 0;
    forn(i, 0, p){
      int x = P[i];
      auto r = ms.upper_bound(min(x+d, s-x));
      if(r == ms.begin())continue;
      r--;
      int vr = *r;
      if(x-d > vr)continue;
      ans++;
      ms.erase(r);
    }
    return ans >= n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> q >> s;
  P.resize(p);
  Q.resize(q);
  forn(i, 0, p)cin >> P[i];
  forn(i, 0, q)cin >> Q[i];

  sort(P.rbegin(), P.rend());
  sort(Q.begin(), Q.end());

  int l = 0, r = s+1;

  while(l < r){
      int m = (l+r)/2;
      if(f(m))r = m;
      else l = m+1;
  }

  if(l == s+1)cout << "-1" << endl;
  else cout << l << endl;

}