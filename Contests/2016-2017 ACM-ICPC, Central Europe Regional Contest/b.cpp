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

const int MAX = 22;
int out[2][MAX], val[2][MAX], MASK[2], sz[2], deg[2][1<<MAX], sum[2][1<<MAX];
bool dp[1<<MAX][MAX][2], vis[1<<MAX][MAX][2];


bool f(int mask, int i, int it){
	if(i == -1)return __builtin_popcount(deg[it][mask]) >= __builtin_popcount(mask);
	bool &ans = dp[mask][i][it];
	if(vis[mask][i][it])return ans;
	vis[mask][i][it] = true;
	ans = f(mask, i-1, it);
	if(mask >> i & 1) ans &= f(mask^(1 << i), i-1, it);
	return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  forn(i, 0, 2){
		cin >> sz[i];
		MASK[i] = (1 << sz[i]);
	}

  string s;

  forn(i, 0, sz[0]){
		cin >> s;
      forn(j, 0, sz[1]){
				char c = s[j];
          if(c == '1'){
              out[0][i] ^= (1 << j);
              out[1][j] ^= (1 << i);
          }
      }
  }

	forn(it, 0, 2){
		forn(i, 0, sz[it]) cin >> val[it][i];
	}

	int t; cin >> t;

	forn(it, 0, 2){
		forn(mask, 0, MASK[it]){
			forn(i, 0, sz[it]){
				if(mask >> i & 1){
					deg[it][mask] |= out[it][i];
					sum[it][mask] += val[it][i];
				}
			}
		}
	}

	vector<int> W[2];

	forn(it, 0, 2){
		forn(mask, 0, MASK[it]){
			if(f(mask, sz[it]-1, it)){
				W[it].pb(sum[it][mask]);
			}
		}
	}

	forn(i, 0, 2){
		sort(W[i].begin(), W[i].end());
	}

ll ans = 0;

	for(auto x: W[0]){
		int aux = t-x;
		int pos = lower_bound(W[1].begin(), W[1].end(), aux) - W[1].begin();
		ans += W[1].size() - pos;
	}

	cout << ans << endl;

  


  
}