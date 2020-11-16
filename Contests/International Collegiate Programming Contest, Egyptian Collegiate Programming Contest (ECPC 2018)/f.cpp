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

int n, m, x, y;

bool f (int z) {
  return (m + z) / (x + y) >= n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("mosalah.in", "r" , stdin);
  
  int t, l, r, mid;
  cin >> t;
  while (t--) { 
    cin >> n >> m >> x >> y;
    if (y == 0 && m / x < n) {
      cout << -1 << endl;
      continue;
    }
    l = 0, r = 1e8;
    while (l <= r) {
      mid = (l + r) / 2;
      if (f(mid)) r = mid - 1;
      else l = mid + 1;
    }
    cout << l << endl;
  } 
}