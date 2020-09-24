/*
Solutions to the contest: https://vjudge.net/contest/369149
*/
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
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005, inf = 1e9;
ll dp[N][N][5];
int n;
ll b;
pii cows[N]; // col, row

ll dist(int i, int j){
  if(j == n)return b-cows[i].F;
  return cows[j].F-cows[i].F;
}


/*
0 : cerrado
1 : abierto row 1
2 : abierto row 2
3 : abierto ambas
4 : abierto doble
*/

ll f(int i, int k, int mask){
  if(k < 0)return inf;
  if(i == n)return 0;
  ll &ans = dp[i][k][mask];
  if(ans != -1)return ans;
  ans = inf;
  int row = cows[i].S;
  int nxt = (row+1)%2;
  ll extra = (mask >> nxt & 1) ? dist(i, i+1) : 0;
  if(mask == 4){ // doble
    ans = min(ans, f(i+1, k, 0)); // cerrar
    ans = min(ans, f(i+1, k, mask)+dist(i, i+1)*2); // seguir
  }else if(mask >> row & 1){ // abierto
    ans = min(ans, f(i+1, k, mask^(1 << row))+extra); // cerrar
    ans = min(ans, f(i+1, k, mask)+dist(i, i+1)+extra); // seguir
  }else if(mask == 0){ // nada abierto
    ans = min(ans, f(i+1, k-1, mask^(1 << row))+dist(i, i+1)+1); // abrir 1
    ans = min(ans, f(i+1, k-1, mask)+1);
    ans = min(ans, f(i+1, k-1, 4)+2+dist(i, i+1)*2); // abrir 2
    ans = min(ans, f(i+1, k-1, mask)+2);
  }else { // cerrado
    ans = min(ans, f(i+1, k-1, mask^(1<<row))+dist(i, i+1)+extra+1); // abrir
    ans = min(ans, f(i+1, k-1, mask)+extra+1);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int k;
  cin >> n >> k >> b;
  forn(i, 0, n){
    cin >> cows[i].S >> cows[i].F;
    cows[i].F--;
    cows[i].S--;
  }
  sort(cows, cows+n);

  memset(dp, -1, sizeof dp);
  cout << f(0, k, 0) << endl;



}



