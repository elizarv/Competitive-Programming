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

const int N = 1005;
int dp[N][N], song[N], gone[N], chairs[N][N];
int n;

bool f(int turn, int i){
  if(turn+1 == n)return true;
  int &ans = dp[turn][i];
  if(ans != -1)return ans;
  ans = false;
  int mod = n-turn;
  if(turn+1 < n){
    int nxtr = (i+song[turn])%mod;
    if(chairs[turn][nxtr] != gone[turn]){
      if(gone[turn] < chairs[turn][nxtr])nxtr = nxtr-1;
      ans = ans | f(turn+1, nxtr);
    }
    int nxtl = (i-(song[turn]%mod)+mod)%mod;
    if(chairs[turn][nxtl] != gone[turn]){
      if(gone[turn] < chairs[turn][nxtl])nxtl = nxtl-1;
      ans = ans | f(turn+1, nxtl);
    }
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int p;
  cin >> n >> p;
  p--;
  forn(i, 0, n-1){
    cin >> song[i];
  } 
  forn(i, 0, n-1){
    cin >> gone[i];
    gone[i]--;
  }
  bitset<N> bs = 0;
  forn(i, 0, n)chairs[0][i] = i;
  forn(i, 1, n){
    bs[gone[i-1]] = true;
    int k = 0;
    forn(j, 0, n){
      if(bs[j])continue;
      chairs[i][k] = j;
      k++;
    }
  }


  memset(dp, -1, sizeof dp);
  if(f(0, p))cout << "Yes";
  else cout << "No";
  cout << endl;
  

}



