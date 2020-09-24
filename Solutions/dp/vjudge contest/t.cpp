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

const int N = 20;
ll dp[N][2][18][2][4][6][8][10]; // i, zero, mask, flag, 3, 5, 7, 9
string a, b;

bool check(int mask, int mod3, int mod5, int mod7, int mod9){
  bool ans = true;
  if((mask >> 1 & 1) && !mod3)ans = false;
  if((mask >> 2 & 1) && !mod5)ans = false;
  if((mask >> 3 & 1) && !mod7)ans = false;
  if((mask >> 4 & 1) && !mod9)ans = false;
  return ans;
}

int getmask(int mask, int j){
  if(j == 3)return mask | (1<<1);
  if(j == 5)return mask | (1<<2);
  if(j == 7)return mask | (1<<3);
  if(j == 9)return mask | (1<<4);
  return mask | 1;
}

ll f(int i, bool zero, int mask, int flag, int mod3, int mod5, int mod7, int mod9, int& n, string& s){
  if(i == n){
    return check(mask, mod3, mod5, mod7, mod9);
  }
  ll &ans = dp[i][zero][mask][flag][mod3][mod5][mod7][mod9];
  if(ans != -1)return ans;
  ans = 0;
  int lim = s[i]-'0';
  if(flag) lim = 9;
  for(int j = zero; j < lim+1; j++){
    if(j && j%2 == 0)continue;
    if(j == 1)continue;
    int nmask = getmask(mask, j);
    int nflag = flag | (j < lim);
    int nzero = zero | (j != 0);
    int n3 = (mod3*10+j)%3;
    int n5 = (mod5*10+j)%5;
    int n7 = (mod7*10+j)%7;
    int n9 = (mod9*10+j)%9;
    ans += f(i+1, nzero, nmask, nflag, n3, n5, n7, n9, n, s);
  }
  return ans;
}

vector<int> r;
void build(int i, bool zero, int mask, int flag, int mod3, int mod5, int mod7, int mod9, int& n, string& s, ll k){
  if(i == n)return;
  ll &ans = dp[i][zero][mask][flag][mod3][mod5][mod7][mod9];
  int lim = s[i]-'0';
  if(flag) lim = 9;
  ll acum = 0;
  for(int j = zero; j < lim+1; j++){
    if(j && j%2 == 0)continue;
    if(j == 1)continue;
    int nmask = getmask(mask, j);
    int nflag = flag | (j < lim);
    int nzero = zero | (j != 0);
    int n3 = (mod3*10+j)%3;
    int n5 = (mod5*10+j)%5;
    int n7 = (mod7*10+j)%7;
    int n9 = (mod9*10+j)%9;
    if(k <= acum+f(i+1, nzero, nmask, nflag, n3, n5, n7, n9, n, s)){
      r.pb(j);
      build(i+1, nzero, nmask, nflag, n3, n5, n7, n9, n, s, k-acum);
      break;
    }
    acum += f(i+1, nzero, nmask, nflag, n3, n5, n7, n9, n, s);
  }
}





int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  ll k, num;
  cin >> t;
  while(t--){
    r.clear();
    cin >> num >> b >> k;
    num--;
    a = to_string(num);
    int n = a.size(), m = b.size();
    memset(dp, -1, sizeof dp);
    ll x = f(0, 0, 0, 0, 0, 0, 0, 0, n, a); 
    memset(dp, -1, sizeof dp);
    ll ans = f(0, 0, 0, 0, 0, 0, 0, 0, m, b); 
    if(k > ans-x){
      cout << "-1" << endl;
      continue;
    }
    build(0, 0, 0, 0, 0, 0, 0, 0, m, b, k+x); 
    bool zero = false;
    for(int i = 0; i < r.size(); i++){
      if(r[i] != 0)zero |= 1;
      if(zero)cout << r[i];
    }cout << endl;
  }

}


