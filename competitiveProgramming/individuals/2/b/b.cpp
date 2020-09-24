#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
int val[N];


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, x, y;
  cin >> n >> m;

  forn(i, 0, n){
      cin >> val[i];
  }

  ll ans = 0;

  forn(i, 0, m){
      cin >> x >> y;
      x--, y--;
      ans += min(val[x], val[y]);
  }

  cout << ans << endl;
    
  
}
