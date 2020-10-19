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

//Maximum bipartite matching O(V*E)

struct mbm {
  int l, r;
  vector<vector<int>> g;
  vector<int> match, seen;
  mbm(int l, int r) : l(l), r(r), seen(r), match(r), g(l) {}
  void add_edge(int l, int r) { g[l].push_back(r); }
  bool dfs(int u) {
    for(auto v : g[u]) {
      if(seen[v]++) continue;
      if(match[v] == -1 || dfs(match[v])) {
        match[v] = u;
        return true;
      }
    }
    return false;
  }
  int max_matching(int m) {
    int ans = 0;
    fill(match.begin(), match.end(), -1);
    for(int u = 0; u < m+1; ++u) {
      fill(seen.begin(), seen.end(), 0);
      ans += dfs(u);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x, t, lim = 1001;
  cin >> n;
	
  mbm mat(lim, n);
  forn(i, 0, n){
	  cin >> x;
	  forn(j, 0, x){
		  cin >> t;
		  mat.add_edge(t, i);
	  }
  }

  int l = n, r = lim;

  while(l < r){
	  int m = (l+r)/2;
	  if(mat.max_matching(m) == n)r = m;
	  else l = m+1;
  }

	cout << l+1 << endl;


	


}