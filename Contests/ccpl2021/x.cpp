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

const int N = (1 << 16);

ll c1[N],c2[N];
void fht(ll* p, int n, bool inv){
	for(int l=1;2*l<=n;l*=2)for(int i=0;i<n;i+=2*l)forn(j,0,l){
		ll u=p[i+j],v=p[i+l+j];
		if(!inv)p[i+j]=u+v,p[i+l+j]=u-v;
		else p[i+j]=(u+v)/2,p[i+l+j]=(u-v)/2;
	}
}

vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
	int n=1<<(32-__builtin_clz(max(SZ(p1),SZ(p2))-1));
	forn(i,0,n)c1[i]=0,c2[i]=0;
	forn(i,0,SZ(p1))c1[i]=p1[i];
	forn(i,0,SZ(p2))c2[i]=p2[i];
	fht(c1,n,false);fht(c2,n,false);
	forn(i,0,n)c1[i]*=c2[i];
	fht(c1,n,true);
	return vector<ll>(c1,c1+n);
}

const int MX = 1e5+5;
int n;
vector<ll> a(N), b(N);
vector<pii> g[MX];
int xr[MX];

void init(){
  forn(i, 0, n+1){
    g[i].clear();
    xr[i] = 0;
  }
  forn(i, 0, N){
    c1[i] = c2[i] = a[i] = b[i] = 0;
  }
}

void dfs(int u, int p, int d = 0){
  xr[u] = d;
  for(auto &ed: g[u]){
    int v = ed.F;
    if(v == p)continue;
    dfs(v, u, d ^ ed.S);
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, test = 1;
  cin >> t;
  while(t--){
    cout << "Case " << test++ << ":" << endl;
    cin >> n;
    init();
    forn(i, 1, n){
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g[u].pb({v, w});
      g[v].pb({u, w});
    }
    dfs(0, -1);
    forn(i, 0, n){
      a[xr[i]]++;
      b[xr[i]]++;
    }
    vector<ll> ans = multiply(a, b);
    ans[0] -= n;
    forn(i, 0, N){
      cout << ans[i]/2 << endl;
    }

  }



}