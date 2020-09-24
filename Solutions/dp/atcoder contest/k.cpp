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

const int N = 100005, M = 105;
int dp[N], n;
int A[M];

int f(int i){
    if(i < 0)return 1;
    if(i == 0)return 0;
    int &ans = dp[i];
    if(ans != -1)return ans;
    ans = 0;
    forn(k, 0, n){
        ans |= !f(i-A[k]);
    }
    return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int k;
  cin >> n >> k;
  forn(i, 0, n)cin >> A[i];

  memset(dp, -1, sizeof dp);
  int ans = f(k);
  if(ans) cout << "First";
  else cout << "Second";
  cout << endl;



}



