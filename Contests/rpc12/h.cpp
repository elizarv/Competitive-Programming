#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct task {
  int s, e, points, id;

  bool operator < (const task &b) const {
    if(s == b.s) return e < b.e;
    return s < b.s;
  }
};

const int MX = 1e4+5;
double prob[MX], dp[MX];
bitset<MX> vis;
vector<task> v;
int t;

double f(int i){
  if(i == t)return 0;
  double &ans = dp[i];
  if(vis[i])return ans;
  vis[i] = 1;
  ans = max(ans, f(i+1));
  task tsk = {v[i].e, 0, 0, 0};
  int nxt = lower_bound(v.begin(), v.end(), tsk) - v.begin();
  ans = max(ans, f(nxt) + prob[v[i].id]*v[i].points);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> t >> n;

  forn(i, 0, t){
    int s, e, p;
    cin >> s >> e >> p;
    v.pb({s, e, p, i});
  }

  sort(v.begin(), v.end());

  vector<pair<double, int>> ans(n);

  forn(i, 0, n){
    forn(j, 0, t){
      cin >> prob[j];
      dp[j] = 0.0f;
    }
    vis = 0;
    ans[i] = {f(0), i};
  }

  sort(ans.rbegin(), ans.rend());
  forn(i, 0, 3){
    cout << ans[i].S+1 << " ";
    cout << fixed << setprecision(2) << ans[i].F << endl;
  }
  
}
