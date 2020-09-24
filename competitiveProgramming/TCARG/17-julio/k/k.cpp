#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... arribargs>
void debug(T a,arribargs... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  ll x, y, t1, t2;

  cin >> n >> m;
  vector<pair<ll, ll> > isl;
  
  forn(i, 0, n){
      cin >> x >> y;
      isl.pb({x, y});
  }

  vector<pair<pair<ll, ll>, int> > dist;
  forn(i, 1, n){
      t1 = isl[i].S - isl[i-1].F;
      t2 = isl[i].F - isl[i-1].S;
      dist.pb({{t1, t2}, i-1});
  }

  sort(dist.begin(), dist.end());

  set<pair<ll, int> > brid;

  forn(i, 0, m){
      cin >> x;
      brid.insert(make_pair(x, i+1));
  }

  bool f = true;
  vector<int> ans(n-1);

  for(auto nx: dist){
      if(brid.empty()){
          f = false;
          break;
      }
      auto it = *brid.lower_bound(make_pair(nx.F.S, 0));
      if(it.F > nx.F.F){
          f = false;
          break;
      }
      ans[nx.S] = it.S;
      brid.erase({it.F, it.S});
  }

  if(!f)cout << "No" << endl;
  else{
      cout << "Yes" << endl;
      forn(i, 0, n-1){
          cout << ans[i] << " \n"[i+1 == n-1];
      }
  }

}

