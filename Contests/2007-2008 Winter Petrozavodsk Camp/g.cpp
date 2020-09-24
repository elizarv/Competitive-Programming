//https://www.urionlinejudge.com.br/judge/en/problems/view/1503
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
typedef unsigned long long ull;
typedef pair<int, int> pii;

struct sat2 {
  int n;
  vector<vector<vector<int>>> g;
  vector<int> tag;
  vector<bool> seen, value;
  stack<int> st;
  sat2(int n) : n(n), g(2, vector<vector<int>>(2*n)), tag(2*n), seen(2*n), value(2*n) { }
  int neg(int x) { return 2*n-x-1; }
  void add_or(int u, int v) { implication(neg(u), v); }
  void make_true(int u) { add_edge(neg(u), u); }
  void make_false(int u) { make_true(neg(u)); }
  void eq(int u, int v) {
    implication(u, v);
    implication(v, u);
  }
  void diff(int u, int v) { eq(u, neg(v)); }
  void implication(int u, int v) {
    add_edge(u, v);
    add_edge(neg(v), neg(u));
  }
  void add_edge(int u, int v) {
    g[0][u].push_back(v);
    g[1][v].push_back(u);
  }
  void dfs(int id, int u, int t = 0) {
    seen[u] = true;
    for(auto& v : g[id][u])
      if(!seen[v])
        dfs(id, v, t);
    if(id == 0) st.push(u);
    else tag[u] = t;
  }
  void kosaraju() {
    for(int u = 0; u < n; u++) {
      if(!seen[u]) dfs(0, u);
      if(!seen[neg(u)]) dfs(0, neg(u));
    }
    fill(seen.begin(), seen.end(), false);
    int t = 0;
    while(!st.empty()) {
      int u = st.top(); st.pop();
      if(!seen[u]) dfs(1, u, t++);
    }
  }
  bool satisfiable() {
    kosaraju();
    for(int i = 0; i < n; i++) {
      if(tag[i] == tag[neg(i)]) return false;
      value[i] = tag[i] > tag[neg(i)];
    }
    return true;
  }

	vector<int> getvals(){
		vector<int> ans;
		forn(i, 0, n){
			if(value[i])ans.pb(i);
		}
		return ans;
	}

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	// freopen("show.in", "r", stdin);
 	// freopen("show.out", "w", stdout);

	int n, m, x;
	cin >> n;
	vector<int> diag(n);
	vector<vector<int> > cnt(n);

	forn(i, 0, n)cin >> diag[i];

	cin >> m;
	vector<int> v[m];
		
	sat2 sat(m);

	forn(i, 0, m){
		int c = 0;
			forn(j, 0, n){
				cin >> x;
				if(x == diag[j]){
					cnt[j].pb(i);
					c++;
				}
				v[i].pb(x);
			}
		if(c != 1)sat.add_or(sat.neg(i), sat.neg(i));
	}

	forn(i, 0, n){
		if(cnt[i].size() == 1){
			sat.add_or(cnt[i][0], cnt[i][0]);
		}else if(!cnt[i].size()){
			cout << "NO" << endl;
			return 0;
		}
	}



	forn(i, 0, m){
		forn(j, i+1, m){
			int t = 0;
			bool xr = false, nand = false;
			forn(k, 0, n){
				if(v[i][k] == v[j][k]){
					if(v[i][k] == diag[k]){
						xr = true;
					}else{
						nand = true;
					}
				}
			}
			if(xr){
				sat.diff(i, j);
			}
			if(nand){
				sat.add_or(sat.neg(i), sat.neg(j));
			}
		}
	}

	if(!sat.satisfiable())cout << "NO" << endl;
	else{
		vector<int> r = sat.getvals();
		cout << "YES" << endl;
		vector<int> ans(n);
		for(auto i: r){
			forn(k, 0, n){
				if(v[i][k] == diag[k]){
					ans[k] = i+1;
					break;
				}
			}
		}
		forn(i, 0, n)cout << ans[i] << " \n"[i+1 == n];
	}




 }
