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

const ll inf = 1e18+10;
map<pii, int> costR, costO; // { R , O }
map<pii, set<int>> ids;

ll oneWay (pii A, pii B, ll CA, ll CB) {
    ll ans = 0;
    if (ids.count(A)){
        ans += CA*ids[A].size();
				ids[A].clear();
    }
    if (ids.count(B)){
        ans += CB*ids[B].size();
				ids[B].clear();
    }
    return ans;
}

ll round(pii A, pii B, ll CAB){
		if(!ids.count(A))return 0;
    auto &idA = ids[A];
    ll ans = 0;
		vector<int> v;
    for(int x: idA){
				if(!ids.count(B))break;
        auto nx = ids[B].lower_bound(x);
        if(nx == ids[B].end())break;
        ans += CAB;
				v.pb(x);
        ids[B].erase(nx);
    }
		for(auto &x: v) idA.erase(x);
    return ans;
}




int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  int a, b;
  cin >> a;

  forn(i, 1, m){
      cin >> b;
      ids[{a, b}].insert(i);
      a = b;
  }

  int q, p;
  char c;
  cin >> q;

  forn(i, 0, q){
      cin >> a >> b >> c >> p;
      if(c == 'R'){
        if(!costR.count({a, b}))costR[{a, b}] = p;
        else{
					int &cur = costR[{a, b}];
					cur = min(cur, p);
				}
      }
			if(!costO.count({a, b}))costO[{a, b}] = p;
			else{
				int &cur = costO[{a, b}];
				cur = min(cur, p);
			}
  }

	ll ans = 0;

  for(auto &x: ids){
      auto A = x.F;
			ll CAB, CA, CBA, CB;
			CAB = CA = CBA = CB = inf;
			if(costR.count(A)) CAB = costR[A]; // cost round A-B-A
      if(costO.count(A)) CA = costO[A]; // cost A-B
      pii B = {A.S, A.F};
      if(costR.count(B)) CBA = costR[B]; // cost round B-A-B
      if(costO.count(B)) CB = costO[B]; // cost B-A
      if(CBA < CAB){
          swap(A, B);
          swap(CB, CA);
          swap(CBA, CAB);
      }
      if(CA + CB <= min(CAB, CBA)){
          ans += oneWay(A, B, CA, CB);
      }else{
          ans += round(A, B, CAB);
          if(CBA <= CA + CB)ans += round(B, A, CBA);
          ans += oneWay(A, B, CA, CB);
      }
  }

  cout << ans << endl;

}