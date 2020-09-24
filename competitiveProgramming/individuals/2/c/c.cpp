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

const int N = 1e5+2;
vector<int> P[N];
vector<pii> Q[N];

int bit[N+1];

void add(int k, int val){
  for(; k <= N; k+=k&-k) bit[k] += val;
}

int rsq(int k){
  int sum = 0;
  for(; k >= 1; k-=k&-k) sum += bit[k];
  return sum;
}

int rsq(int i, int j){ return rsq(j)-rsq(i-1); }



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m, l, r;
  cin >> n >> m;
  vector<int> v(n+1);

  forn(i, 1, n+1){
    cin >> v[i];
  }

  forn(i, 0, m){
    cin >> l >> r;
    Q[r].pb({l, i});
  }

  vector<int> ans(m, 0);
  forn(i, 1, n+1){
    int x = v[i];
    if(x > 1e5)continue;
    P[x].pb(i);
    int sz = P[x].size();
    if(sz >= x)add(P[x][sz-x], 1);
    if(sz > x)add(P[x][sz-x-1], -2);
    if(sz > x+1) add(P[x][sz-x-2], 1);
    for(auto q: Q[i]){
      ans[q.S] = rsq(q.F, i);
    }
  }

  forn(i, 0, m)cout << ans[i] << endl;
    
  
}

