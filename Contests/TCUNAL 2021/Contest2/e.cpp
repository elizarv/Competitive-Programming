#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5, inf = 1e9+7;
bitset<N> vis;
ll ans[N], psum[N];
pii range[N];

ll val(int i, int j){
    return psum[j] - psum[i-1];
}

ll sum(int i, int j){
    ll ans = j * (j+1) / 2;
    ans -= i * (i+1) / 2;
    return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<int> v(n+1, 0);

  forn(i, 1, n+1){
      cin >> psum[i];
      psum[i] += psum[i-1];
  }

  memset(ans, -inf, sizeof ans);

  while(q--){
      int k;
      cin >> k;
      if(vis[k]){
          cout << ans[k] << " " << range[k].F << " " << range[k].S << endl;
          continue;
      }
      vis[k] = true;
      ll &r = ans[k];
      pii &ran = range[k];

      int i = k, j = k;
      r = val(i, j);
      ran = {i, j};


      while(j > 1){
          i = j = (j+1)/2;
          while(sum(i, j) < k)i--;
          if(sum(i, j) == k){
              if(val(i, j) > r){
                r = val(i, j);
                ran = {i+1, j};
              }
          }else break;
      }

      cout << r << " " << ran.F << " " << ran.S << endl;
      

  }


}