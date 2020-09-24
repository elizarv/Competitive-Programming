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

const int MAX = 3005;
string s, t, r;
int dp[MAX][MAX], n, m;
pii rec[MAX][MAX];

int f(int i, int j){
    if(i == n || j == m)return 0;
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans = 0;
    ans = max(ans, f(i, j+1));
    ans = max(ans, f(i+1, j));
    ans = max(ans, f(i+1, j+1)+(s[i]==t[j]));
    return ans;
}

void build(int i, int j){
    if(i == n || j == m)return;
    int &ans = dp[i][j];
    if(f(i, j+1) == ans)build(i, j+1);
    else if(f(i+1, j) == ans)build(i+1, j);
    else if(f(i+1, j+1)+(s[i]==t[j]) == ans){
        r.pb(s[i]);
        build(i+1, j+1);
    }
}

//botton-up
int lcs(){
    dp[0][0] = 0;
    forn(i, 0, n+1){
        forn(j, 0, m+1){
            int &ans = dp[i][j];
            if(i){
                if(dp[i-1][j] > ans){
                    ans = dp[i-1][j];
                    rec[i][j] = {i-1, j};
                }
            }
            if(j){
                if(dp[i][j-1] > ans){
                    ans = dp[i][j-1];
                    rec[i][j] = {i, j-1};
                }
            }
            if(i && j){
                if(dp[i-1][j-1]+(s[i-1]==t[j-1]) > ans){
                    ans = dp[i-1][j-1]+(s[i-1]==t[j-1]);
                    rec[i][j] = {i-1, j-1};
                }
            }
        }
    }
    return dp[n][m];
}

string buildlcs(){
    int i = n, j = m;
    string r;
    while(i > 0 && j > 0){
        pii prev = rec[i][j];
        i = prev.F;
        j = prev.S;
        if(s[i] == t[j])r.pb(s[i]);
    }
    return r;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> s >> t;

  n = s.size(), m = t.size();
  memset(dp, -1, sizeof dp);
//   f(0, 0);
//   build(0, 0);
  lcs();
  string ans = buildlcs();
  reverse(ans.begin(), ans.end());
  cout << ans << endl;


}



