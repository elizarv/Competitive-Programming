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

const int inf = 1e9;
const int MX = 105;
string s, t, p;
int n, m, x;
int pf[MX];
int dp[MX][MX][MX];

int f(int i, int j, int k){
    if(i == n || j == m) return 0;
    int &ans = dp[i][j][k];
    if(ans != -1)return ans;
    ans = 0;
    if(s[i] == t[j]){
        if(s[i] == p[k]){
            if(k+1 < x)ans = max(ans, f(i+1, j+1, k+1) + 1);
        }else{
            while(k && p[k] != s[i]){
                k = pf[k-1];
            }
            if(p[k] == s[i]) k++;
            ans = max(ans, f(i+1, j+1, k) + 1);
        }
    }
    ans = max(ans, f(i+1, j, k));
    ans = max(ans, f(i, j+1, k));
    return ans;
}

vector<int> r;

void build(int i, int j, int k){
    if(i == n || j == m) return;
    int &ans = dp[i][j][k];
    if(s[i] == t[j]){
        if(s[i] == p[k]){
            if(k+1 < x && ans == f(i+1, j+1, k+1) + 1){
                r.pb(i);
                build(i+1, j+1, k+1);
                return;
            }
        }else{
            while(k && p[k] != s[i]){
                k = pf[k-1];
            }
            if(p[k] == s[i]) k++;
            if(ans == f(i+1, j+1, k) + 1){
                r.pb(i);
                build(i+1, j+1, k);
                return;
            }
        }
    }
    if(ans == f(i+1, j, k)){
        build(i+1, j, k);
        return;
    }
    build(i, j+1, k);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> s >> t >> p;
  n = s.size();
  m = t.size();
  x = p.size();

  pf[0] = 0;
  for(int i = 1, j = 0; i < x; i++){
      while(j && p[i] != p[j])j = pf[j-1];
      if(p[i] == p[j])j++;
      pf[i] = j;
  }


  memset(dp, -1, sizeof dp);

  int ans = f(0, 0, 0);
  if(!ans) cout << ans << endl;
  else{
    build(0, 0, 0);
    for(auto x: r){
        cout << s[x];
    }
    cout << endl;
  }

  
  
}