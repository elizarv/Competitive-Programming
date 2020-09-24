#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;
int S[MAX], LIS[MAX];
int val[MAX][MAX];
int dp[MAX], n;

int lis(int L, int R) {
    forn(i, L, R) LIS[i] = 1;

    forn(i, L, R){
        forn(j, i+1, R){
            if(S[j] > S[i]){
                if(LIS[j] < LIS[i]+1) LIS[j] = LIS[i]+1;
            }
        }
    }

    int mx = 0;
    forn(i, L, R){
        mx = max(mx, LIS[i]);
    }
    return mx;
}

int f(int i,  int k){
    if(i == n) return 0;
    int &ans = dp[i];
    if(ans != -1)return ans;
    ans = 0;
    forn(j, i, n){
        ans = max(ans, f(j, k));
        if(val[i][j] >= k)ans = max(ans, f(j+1, k)+val[i][j]);
    }
    return ans;
}



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;

  cin >> t;

  while(t--){
      cin >> n;
      forn(i, 0, n){
          cin >> S[i];
      }

      forn(i, 0, n){
          forn(j, 0, n){
              val[i][j] = lis(i, j+1);
          }
      }

      forn(k, 1, n+1){
          memset(dp, -1, sizeof dp);
          cout << f(0, k) << " \n"[k==n];
      }

  }

  
}
