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

const int MX = 2e5+5;
set<int> g[MX];
int deg[MX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int c, p, x, l;
	cin >> c >> p >> x >> l;
	x--, l--;
	int u, v;
	forn(i, 0, p){
		cin >> u >> v;
		u--, v--;
		g[u].insert(v);
		g[v].insert(u);
		deg[u]++;
		deg[v]++;
	}
	queue<int> q;
	q.push(l);
	while(q.size()){
		u = q.front();
		q.pop();
		if(u == x){
			cout << "leave"<< endl;
			return 0;
		}
		for(auto v: g[u]){
			g[v].erase(u);
			int left = deg[v]-g[v].size();
			if(2*left >= deg[v])q.push(v);
		}
	}
	cout << "stay" << endl;


}