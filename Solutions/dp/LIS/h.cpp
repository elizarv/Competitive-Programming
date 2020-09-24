// https://codeforces.com/gym/102318/problem/H

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

const int N = 105;
int arr[N], lis[N][N], dp[N][N], n;

void LIS(){
  forn(i, 0, n){
    forn(j, i, n){
      lis[i][j] = 1;
      forn(k, i, j+1){
        if(arr[k] < arr[j]){
          lis[i][j] = max(lis[i][j], lis[i][k]+1);
        }
      }
    }
  }
}

int f(int i, int k){
  if(i == n)return 0;
  int &ans = dp[i][k];
  if(ans != -1)return ans;
  ans = 0;
  forn(j, i, n){
    if(lis[i][j] >= k){
      ans = max(ans, f(j+1, k)+lis[i][j]);
    }
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    forn(i, 0, n)cin >> arr[i];
    LIS();
    memset(dp, -1, sizeof dp);
    forn(i, 1, n+1){
      cout << f(0, i) << " \n"[i == n];
    }
  }



}



