//https://codeforces.com/gym/102920/problem/J
#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef double lf;

const int N = 501;

int gauss (vector<bitset<N>> &a, vector<bitset<N>> &b, int n, int m, vector<bitset<N>> &ans) {
  vector<int> where(m, -1);
  for(int col = 0, row = 0; col < m && row < n; ++col) {
    for(int i = row; i < n; ++i){
      if(a[i][col]){
        swap(a[i], a[row]);
        swap(b[i], b[row]);
        break;
      }
    }
    if(!a[row][col])continue;
    where[col] = row;
    for(int i = 0; i < n; ++i)
      if(i != row && a[i][col]) {
        a[i] ^= a[row];
        b[i] ^= b[row];
      }
    ++row;
  }
  ans.assign(m, 0);
  for(int i = 0; i < m; ++i)
    if(where[i] != -1) ans[i] = b[where[i]];
  for(int i = 0; i < n; ++i) {
    if(ans[i] == 0) return 0;
  }
  for(int i = 0; i < m; ++i)
    if(where[i] == -1) return -1; /// infinite solutions
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  vector<bitset<N>> mat(n, 0), r(n, 0);
  forn(i, 0, n){
    forn(j, 0, n){
      int x; cin >> x;
      mat[i][j] = x;
    }
    r[i][i] = 1;
  }

  vector<bitset<N>> ans;
  if(!gauss(mat, r, n, n, ans)){
    cout << "-1" << endl;
  }else{
    forn(i, 0, n){
      forn(j, 0, n){
        if(ans[i][j]){
          cout << j+1 << " ";
        }
      }cout << endl;
    }
  }
}