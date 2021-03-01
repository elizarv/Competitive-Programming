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
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct node{
  ll ans;
  vector<ll> cnt;
  node(){
    ans = 0;
    cnt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  }
};

const int N = 15;
node dp[N][2];
ll cnt[N][2];
bool vis[N][2];
string s;
int n;

ll g(int i, int menor){
  if(i == n)return 1;
  ll &ans = cnt[i][menor];
  if(ans != -1)return ans; 
  ans = 0;
  int dig = s[i]-'0';
  int lim = 10;
  if(!menor)lim = dig+1;
  forn(d, 0, lim){
    bool nxtm = menor | (d < dig);
    ans += g(i+1, nxtm);
  }
  return ans;
}

void merge(node &ans, int d, node nxt){
  ans.ans += nxt.ans;
  forn(i, 0, 10){
    if(i > d)ans.ans += nxt.cnt[i];
    ans.cnt[i] += nxt.cnt[i];
  }
}


node f(int i, bool menor){
  if(i == n)return node();
  node &ans = dp[i][menor];
  if(vis[i][menor])return ans;
  vis[i][menor] = true;
  int dig = s[i] - '0';
  int lim = 10;
  if(!menor)lim = dig+1;
  forn(d, 0, lim){
    bool nxtm = menor | (d < dig);
    node nxt = f(i+1, nxtm);
    merge(ans, d, nxt);
    ans.cnt[d] += g(i+1, nxtm);
  }
  return ans;
}

void init(){
  forn(i, 0, n+1){
    forn(j, 0, 2){
      dp[i][j] = node();
      vis[i][j] = 0;
      cnt[i][j] = -1;
    }
  }
}

ll go(){
  ll ans = 0;
  forn(i, 0, n){
    bool menor = true;
    int lim = 10;
    int dig = s[i]-'0';
    if(!i)lim = dig+1;
    vector<ll> aux(10, 0);
    forn(d, 1, lim){
      if(!i && d == dig)menor = false;
      else menor = true;
      node nxt = f(i+1, menor);
      ans += nxt.ans;
      forn(j, d+1, 10){
        ans += nxt.cnt[j];
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, caso = 1;
  cin >> t;
  while(t--){
    ll x, y;
    cin >> x >> y;
    s = to_string(y), n = s.size();
    init();
    ll b = go();

    s = to_string(x-1), n = s.size();
    init();
    ll a = go();

    cout << "Case "<< caso++ << ": " << b-a << endl;
    
  }

}
