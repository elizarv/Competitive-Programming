#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5+5, inf = 1e9+5;
map<pii, int> cost[2]; // 0: one way, 1: round
map<pii, vector<int>> p;
int N;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, d;
  cin >> n >> d;
  
  int a, b;
  cin >> a;
  forn(i, 1, n){
      cin >> b;
      p[{a, b}].pb(i);
      a = b;
  }
	
	int u, v, w;
	char c;
  forn(i, 0, d){
		cin >> u >> v >> c >> w;
		if(c == 'R'){
			if(!cost[1].count({u, v}))cost[{u, v}] = w;
			else cost[1][{u, v}] = min(cost[1][{u, v}], w);
		}
		if(!cost[0].count({u, v}))cost[{u, v}] = w;
		else cost[0][{u, v}] = min(cost[0][{u, v}], w);
  }

	for(auto nx: p){
		auto x = nx.F;
		auto y = make_pair(x.S, x.F);
		if(!cost[0].count(x))cost[0][x] = inf;
		if(!cost[0].count(y))cost[0][y] = inf;
		if(!cost[1].count(x))cost[1][x] = inf;
		if(!cost[1].count(y))cost[1][y] = inf;
		if(cost[0][x] + cost[0][y] <= cost[1][x] && cost[1][x] <= cost[1][y]){
			oneway(x);
		}else if(cost[1][x] <= cost[0][x] + cost[0][y] && cost[0][x] + cost[0][y] <= cost[1][y]){
			round(x);
			oneway(x);
			oneway(y);
		}else{
			round(x);
			round(y);
			oneway(x);
			oneway(y);
		}
	}




  

}