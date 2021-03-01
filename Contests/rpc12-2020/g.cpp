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

const ll inf = 1e18;

typedef __int128 big;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll x;
  cin >> n >> x;
  big k = (big)x;
  big cnt = 1;
  forn(i, 1, n){
    cnt *= 2;
  }
  if(k > cnt){
    cout << "-1" << endl;
    return 0;
  }
  int l = 1, r = n;
  vector<int> ans;
  while(cnt){
    big m = cnt/2;
    if(k <= m){
      ans.pb(l);
      l++;
    }else{
      ans.pb(r);
      r--;
      k -= m;
    }
    cnt = m;
  }

  n = ans.size();

  forn(i, 0, n){
    cout << ans[i] << " \n"[i+1 == n];
  }
    
}
