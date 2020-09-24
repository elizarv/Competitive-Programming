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
#include <iomanip>
using namespace std;
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long int T;
typedef pair<int, int> pii;

const int N = 55;
const T inf = 1e18;
T dp[N][N], Atotal;
bool X[N][N];
int n;

T absval(T val){
  if(val < 0)val *= -1;
  return val;
}

struct pt{
  T x, y;
  pt(T _x, T _y){
    x = _x;
    y = _y;
  }
  pt operator + (pt p) { 
    return pt(x+p.x, y+p.y);
  }
  pt operator - (pt p) { return pt(x-p.x, y-p.y); }
  pt operator * (pt p) { return pt(x*p.x-y*p.y, x*p.y+y*p.x); }
  pt operator * (T d) { return pt(x*d, y*d); }
  pt operator / (T d) { return pt(x/d, y/d); }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

vector<pt> p;

T cross(pt u, pt v){
  return u.x*v.y - u.y*v.x;
}

T areaPol(int i, int j){
  T ans = 0;
  for(int u = i; u != j; u = (u+1)%n){
    int v = (u+1)%n;
    ans += cross(p[u], p[v]);
  }
  ans += (cross(p[j], p[i]));
  return absval(ans);
}

bool out(int u, int v){
  T sum = areaPol(u, v);
  sum += areaPol(v, u);
  return (sum != Atotal);
}

T area(int i, int j, int k){
  T ans = cross(p[i], p[k]);
  ans += cross(p[k], p[j]);
  ans += cross(p[j], p[i]);
  return absval(ans);
}

bool validate(int i, int j, int k){
  if(X[i][k] || X[j][k])return false;
  return true;
}

T f(int i, int j){
  if((i+1)%n == j)return 0;
  T &ans = dp[i][j];
  if(ans != -1)return ans;
  ans = inf;
  for(int k = i+1; k != j; k = (k+1)%n){
    if(!validate(i, j, k))continue;
    T mx = area(i, j, k);
    mx = max(mx, f(i, k));
    mx = max(mx, f(k, j));
    ans = min(ans, mx);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, x, y;
  cin >> t;
  while(t--){
    cin >> n;
    p.clear();
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      p.push_back(pt(x, y));
    }
    Atotal = 0;
    for(int i = 0; i < n; i++){
      int j = (i+1)%n;
      Atotal += cross(p[i], p[j]);
    }
    Atotal = absval(Atotal);
    memset(X, 0, sizeof X);
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        X[i][j] = X[j][i] = out(i, j);
      }
    }


    memset(dp, -1, sizeof dp);

    cout << fixed << setprecision(1) << f(0, n-1)/2.0 << endl;
  }




}



