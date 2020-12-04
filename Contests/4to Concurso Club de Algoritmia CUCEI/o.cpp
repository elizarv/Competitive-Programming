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

const int N = 1e5+5, K = 105, inf = 1e9;
int d1[N];
vector<int> g[N];
int n, m, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> k;
  forn(i, 0, m){
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }
  




  
  
}