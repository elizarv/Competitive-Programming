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

const int N = 2e5+5, inf  = 1e9+7;
int n;
string S;
int dp[N][2];

int cost(int i, int j, int dir){
  int c = 0;
  char ch1 = 'L', ch2 = 'R';
  if(dir)swap(ch1, ch2);
  c += S[i] != ch1;
  c += S[j] != ch2;
  return c;
}

int f(int i, int j, int dir){
  debug(i, j, dir);
  if(i >= j)return 0;
  int &ans = dp[i][dir];
  if(ans != -1)return ans;
  ans = inf;
  int nxtj = j;
  int prev = j;
  if (!i)nxtj = j-1, prev= i-1; 
  ans = min(ans, f(i+1, nxtj, 0)+cost(i, prev, 0));
  ans = min(ans, f(i+2, nxtj, 1)+cost(i, i+1, 1));
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> S;
    memset(dp, -1, sizeof dp);
    cout << f(0, n-1, 0) << endl;


  }

    
  
}

