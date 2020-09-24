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

const int N = 1e6+5;
const int LOG = 22;
pii arr[N];
int spt[LOG][N], n, color[N];
vector<int> g[N];

void build(){
    forn(i, 0, n)spt[0][i] = arr[i].F;
    forn(j, 0, LOG-1){
        for(int i = 0; i+(1<<(j+1)) <= n; i++){
            spt[j+1][i] = max(spt[j][i], spt[j][i+(1<<j)]);
        }
    }
}

int rmq(int i, int j){
    int k = 31-__builtin_clz(j-i+1);
    return max(spt[k][i], spt[k][j-(1<<k)+1]);
}

int mex(int mask){
	mask = ~mask; // invierte bits
	return mask&-mask; // retorna el mas a la izq encendido
}

void init(){
	memset(color, 0, sizeof color);
	forn(i, 0, n)g[i].clear();
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	freopen("tour.in", "r", stdin);
  
  int t;
  cin >> t;
  while(t--){
      cin >> n;
      forn(i, 0, n){
          cin >> arr[i].F;
					arr[i].S = i;
      }
      build();
			init();
			forn(i, 0, n){
				int l = 0, r = i;
				while(l < r){
					int m = (l+r)/2;
					int query = rmq(m, i-1);
					if(query < arr[i].F)r = m;
					else l = m+1;
				}
				if(l-- >= 0){
					g[i].pb(l);
					g[l].pb(i);
				}

				l = i+1;
				r = n;
				while(l < r){
					int m = (l+r)/2;
					int query = rmq(i+1, m);
					if(query > arr[i].F)r = m;
					else l = m+1;
				}
				if(l < n){
					g[i].pb(l);
					g[l].pb(i);
				}
			}
			int ans = 0;
			sort(arr, arr+n);
			for(int i = n-1; i >= 0; i--){
				int u = arr[i].S;
				int mask = 0;
				for(auto v: g[u]){
					mask |= color[v];
				}
				color[u] = mex(mask);
				ans |= color[u];
			}	
			cout << __builtin_popcount(ans) << endl;
			forn(i, 0, n){
				cout << 31-__builtin_clz(color[i])+1 << " \n"[i+1 == n];
			}

			

  }
  
}



