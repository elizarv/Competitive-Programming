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
typedef long long ll;
typedef pair<int, int> pii;


const int N = 105, M = 1000;
int mat[N][N];

int mex(bitset<M> vis){
  forn(i, 0, M){
    if(!vis[i])return i;
  }
  return N;
}

void pre(){
  forn(i, 1, N){
    forn(j, 1, N){
      if(i == j)continue;
      bitset<M> vis = 0;
      forn(k, 1, i){ // hor
        if(i-k == j)continue;
        vis[mat[i-k][j]] = 1;
      }
      forn(k, 1, j){ // ver
        if(i == j-k)continue;
        vis[mat[i][j-k]] = 1;
      }
      forn(k, 1, min(i, j)){ // diag
        vis[mat[i - k][j - k]] = 1;
      }
      mat[i][j] = mex(vis);
    }
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  pre();
  int n;
  cin >> n;
  int ans = 0;
  forn(i, 0, n){
    int x, y;
    cin >> x >> y;
    if(x == y){
      cout << "Y" << endl;
      return 0;
    }
    ans = ans ^ mat[x][y];
  }

  if(!ans)cout << "N";
  else cout << "Y";
  cout << endl;


}