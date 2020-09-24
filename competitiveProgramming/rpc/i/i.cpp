#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
ll bit[N+1];

void add (int k, int val){
    for(; k <= N; k += k&-k) bit[k] += val;
}

ll rsq(int k){
    ll sum = 0;
    for(; k >= 1; k -= k&-k) sum += bit[k];
    return sum;
}

ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n, x;
  cin >> t;
  while(t--){
      cin >> n;
      vector<int> pos(n+1);
      ll tot = 0;
      forn(i, 1, n+1){
          cin >> x;
          pos[x] = i;
          add(i, x);
          tot += x;
      }
      int ini = 1;
      ll ans = 0;
      forn(i, 1, n+1){
          ll query;
          if(ini >= pos[i]){
              query = rsq(ini, n)+ rsq(1, max(0, pos[i]-1));
          }else{
              query = rsq(ini, pos[i]-1);
          }
          ans += min(query, tot-query);
          tot -= i;
          add(pos[i], -i);
          ini = pos[i];
      }

      cout << ans << endl;
  }

}
