// https://codeforces.com/gym/101492/problem/I
#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef __int128 ll;
typedef pair<int, int> pii;

const double EPS = 1e-6;

struct simplex {
  vector<int> X, Y;
  vector<vector<double>> a;
  vector<double> b, c;
  double z;
  int n, m;

  void pivot(int x, int y) {
    swap(X[y], Y[x]);
    b[x] /= a[x][y];
    for(int i = 0; i < m; i++){
      if(i != y) a[x][i] /= a[x][y];
    }
    a[x][y] = 1 / a[x][y];

    for(int i = 0; i < n; i++){
      if(i != x && abs(a[i][y]) > EPS) {
        b[i] -= a[i][y] * b[x];
        for(int j = 0; j < m; j++){
          if(j != y) a[i][j] -= a[i][y] * a[x][j];
        }
        a[i][y] =- a[i][y] * a[x][y];
      }
    }
    z += c[y] * b[x];
    for(int i = 0; i < m; i++){
      if(i != y) c[i] -= c[y] * a[x][i];
    }
    c[y] =- c[y] * a[x][y];
  }

  simplex(vector<vector<double>> &A, vector<double> &B, vector<double> &C) {
    a = A; b = B; c = C;
    n = b.size(); m = c.size(); z = 0.0;
    X.resize(m); iota(X.begin(), X.end(), 0);
    Y.resize(n); iota(Y.begin(), Y.end(), m);
  }

  // A is a vector of 1 and 0. B is the limit restriction. C is the factors of O.F.
  pair<double, vector<double>> maximize() {
    while(true) {
      int x = -1, y = -1;
      double mn = -EPS;
      for(int i = 0; i < n; i++){
        if(b[i] < mn) mn = b[i], x = i;
      }
      if(x < 0) break;
      for(int i = 0; i < m; i++){
        if(a[x][i] < -EPS) { 
          y = i; 
          break; 
        }
      }
      assert(y >= 0); // no solution
      pivot(x, y);
    }
    while(true) {
      double mx = EPS;
      int x = -1, y = -1;
      for(int i = 0; i < m; i++){
        if(c[i] > mx) mx = c[i], y = i;
      }
      if(y < 0) break;
      double mn = 1e200;
      for(int i = 0; i < n; i++){
        if(a[i][y] > EPS && b[i] / a[i][y] < mn)
          mn = b[i] / a[i][y], x = i;
      }
      assert(x >= 0); // unbound
      pivot(x, y);
    }
    vector<double> r(m);
    for(int i = 0; i < n; i++){
      if(Y[i] < m) r[ Y[i] ] = b[i];
    }
    return {z, r};
  }
};




int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<double> c(n);
  forn(i, 0, n)cin >> c[i];

  vector<vector<double>> a(m, vector<double>(n));
  vector<double> b(m);

  forn(i, 0, m){
    int l, r;
    cin >> l >> r >> b[i];
    forn(j, l-1, r){
      a[i][j] = 1;
    }
  }

  simplex sim(a, b, c);

  cout << (long long)sim.maximize().F << endl;



}