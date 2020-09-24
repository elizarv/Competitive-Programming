//https://codeforces.com/gym/102411
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

const int inf = 1e9;

struct tower {
  int x, y, h;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, x, y, h;
  cin >> n;
  vector<tower> T;
  int u = -inf, d = inf, l = inf, r = -inf;
  forn(i, 0, n){
    cin >> x >> y >> h;
    T.pb({x, y, h});
    u = max(u, y+h);
    d = min(d, y-h);
    l = min(l, x-h);
    r = max(r, x+h);
  }

  x = (l+r)/2;
  y = (u+d)/2;
  h = 0;

  for(auto t: T){
    h = max({h, abs(t.x-x)+t.h, abs(t.y-y)+t.h});
  }

  cout << x << " " << y << " " << h << endl;


}