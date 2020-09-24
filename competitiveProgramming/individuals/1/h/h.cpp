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
  int game[N][N];
  int mxrow[N], mxcol[N];
int n, m;

pii getmax(int r, int c){
    pii ans = {0, 0};
    int mx = 0;
    forn(i, 0, n){
        if(r != -1 && i == r)continue;
        forn(j, 0, m){
            if(c != -1 && j == c)continue;
            if(game[i][j] > mx){
                mx = game[i][j];
                ans = {i, j};
            }
        }
    }
    return ans;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> m;

vector<ll> row;

  forn(i, 0, n){
      bitset<N> bs;
      forn(j, 0, m){
          cin >> game[i][j];

      }
  }
  
  
  pii MAX = getmax(-1, -1);

  pii rowOut = getmax(MAX.F, -1);

  pii mx1 = getmax(MAX.F, rowOut.S);

  pii colOut = getmax(-1, MAX.S);

  pii mx2 = getmax(colOut.F, MAX.S);

  if(game[mx1.F][mx1.S] < game[mx2.F][mx2.S]){
      cout << MAX.F+1 << " " << rowOut.S+1;
  }else {
      cout << colOut.F+1 << " " << MAX.S+1;
  }
  cout << endl;



  
}

