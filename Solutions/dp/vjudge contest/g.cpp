#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
void debug() {cout<<endl;}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 505;
const ll inf = 1e12;
ll a[N], b[N];
int dp[N][N];
int n, m;

int f(int i, int j){
  int &ans = dp[i][j];
  if(ans != -1)return ans;
  ans = 0;
  if(i < n){
    ans = max(ans, f(i+1, j));
    forn(k, j+1, m+1){
      if(a[i+1] == b[k] && a[i+1] > b[j]){
        ans = max(ans, f(i+1, k)+1);
        break;
      }
    }
  }
  return ans;
}

vector<int> r;
void build(int i, int j){
  int &ans = dp[i][j];
  if(i < n){
    if(ans == f(i+1, j)){
      build(i+1, j);
      return;
    }
    forn(k, j+1, m+1){
      if(a[i+1] == b[k]){
        if(ans == f(i+1, k)+1 && a[i+1] > b[j]){
          build(i+1, k);
          r.pb(b[k]);
          break;
        }
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  a[0] = b[0] = -inf;
  forn(i, 1, n+1){
    cin >> a[i];
  }
  cin >> m;
  forn(i, 1, m+1){
    cin >> b[i];
  }
  memset(dp, -1, sizeof dp);
  int ans = f(0, 0);
  cout << ans << endl;
  build(0, 0);
  reverse(r.begin(), r.end());
  for(int i = 0; i < ans; i++){
    cout << r[i] << " \n"[i+1 == ans];
  }
  



}



