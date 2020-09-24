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

const int N = 1005, M = 10005;
ll dp[N][M], inf = 1e18;
int n;

struct block{
  int w, s, v;
  bool operator < (const block &b)const{
    return w+s > b.w+b.s;
  }
};

vector<block> blocks;


ll f(int i, int j){
  if(j < 0)return -inf;
  if(i == n)return 0;
  ll &ans = dp[i][j];
  if(ans != -1)return ans;
  ans = 0;
  ans = max(ans, f(i+1, min(j-blocks[i].w, blocks[i].s))+blocks[i].v);
  ans = max(ans, f(i+1, j));
  return ans;
}




int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int w, s, v;
  cin >> n;
  forn(i, 0, n){
    cin >> w >> s >> v;
    blocks.pb({w, s, v});
  }
  sort(blocks.begin(), blocks.end());
  memset(dp, -1, sizeof dp);
  ll mx = 0;
  forn(i, 0, n){
    mx = max(mx, f(i+1, blocks[i].s)+blocks[i].v);
  }
  cout << mx << endl;

}



