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

const int N = 1005, M = 1e6+5;
int dp[2][N], n, inf = 1e9;

struct box{
  int r, w;
  bool operator < (const box &b) const {
    return r-w > b.r-b.w;
    if(r != b.r)return r > b.r;
  }
};
vector<box> boxes;

int f(int i, int k){
  if(i == n)return 0;
  int &ans  = dp[i%2][k];
  if(ans != -1)return ans;
  ans = 0;
  ans = max(ans, f(i+1, boxes[i+1].r));
  int nxt = i+1 == n ? inf : boxes[i+1].r;
  if(boxes[i].w <= k) ans = max(ans, f(i+1, min(k-boxes[i].w, nxt))+1);
  return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, w, r;
  cin >> t;
  while(t--){
    cin >> n;
    boxes.clear();
    memset(dp, -1, sizeof dp);
    forn(i, 0, n){
      cin >> w >> r;
      boxes.pb({r, w});
    }
    sort(boxes.begin(), boxes.end());
    cout << f(0, boxes[0].r) << endl;

  }



}



