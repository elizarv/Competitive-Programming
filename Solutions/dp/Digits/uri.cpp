//https://www.urionlinejudge.com.br/judge/en/problems/view/1226

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


const int N = 20, D = 10;
const ll MAX = 1e18;
ll dp[N][D];

ll f(int i, int prev){
  if(i == N)return 1;
  ll &ans = dp[i][prev];
  if(ans != -1)return ans;
  ans = 0;
  forn(d, 0, D){
    if(d == 4)continue;
    if(d == 3 && prev == 1)continue;
    ans += f(i+1, d);
    if(ans > MAX)return ans;
  }
  return ans;
}

vector<int> r;
void build(int i, int prev, ll k){
  if(i == N)return;
  ll sum = 0;
  forn(d, 0, D){
    if(d == 4)continue;
    if(d == 3 && prev == 1)continue;
    if(sum+f(i+1, d) >= k){
      r.pb(d);
      build(i+1, d, k-sum);
      return;
    }
    sum += f(i+1, d);
  }
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll n;
  memset(dp, -1, sizeof dp);
  f(0, 0);
  while(cin >> n){
    r.clear();
    build(0, 0, n+1);
    bool flag = false;
    forn(i, 0, r.size()){
      if(r[i] != 0)flag = true;
      if(!flag)continue;
      cout << r[i];
    }cout << endl;
  }



}



