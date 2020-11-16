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

const int N = 2005;
ll inf = 1e18;
ll dp[N][N], vis[N][N], pref[N];
int A[N], B[N], C[N], n, m;
map<int, pii> mapa;

ll f(int i, int j){
    if(j == m) return 0;
    if(i == n) return -inf;
    ll &ans  = dp[i][j];
    if(vis[i][j])return ans;
    vis[i][j] = true;
    ans = -inf;
    if(A[i] == B[j]){
        ll r = f(i + 1, j + 1);
        if(r == -inf)ans = max(ans, r);
        else ans = max(ans, r + C[i]);
    }
    int x = A[i];
    if(mapa[x].F >= j || mapa[x].S < j) ans = max(ans, f(i + 1, j));
    return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("transform.in", "r" , stdin);

  int t;
  cin >> t;
  while(t--){
		int x;
        cin >> n >> m;

        mapa.clear();
        forn(i, 0, n) cin >> A[i];
        forn(i, 0, m){
            cin >> x;
            B[i] = x;
            if(!mapa.count(x)){
                mapa[x] = {i, i};
            }else{
                mapa[x].S = i;
            }
        }

        ll tot = 0;
        forn(i, 0, n){
            cin >> C[i];
            tot += C[i];
        }

        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);

        ll ans = f(0, 0);
        
        if(ans == -inf) cout << "No" << endl;
        else cout << tot - ans << endl;

  }

}