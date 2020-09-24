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

const int N = 200005, inf = 1e9+5;
ll psum[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h, mx = 0, mn = inf;
  ll k;
  cin >> n >> k;
  forn(i, 0, n){
      cin >> h;
      psum[h]++;
      mx = max(mx, h);
      mn = min(mn, h);
  }

    int ans = 0;
    ll acum = 0;
    for(int i = mx; i > mn; i--){
        if(acum + psum[i] > k){
            ans++;
            acum = 0;
        }
        acum += psum[i];
        psum[i-1] += psum[i];
    }
    if(acum)ans++;
    cout << ans << endl;


}



