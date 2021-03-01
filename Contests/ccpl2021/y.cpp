#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 55;
string mat[N];
int cont[N*N];
char ans[N*N];
bitset<N> vis[N];
int n, m, cnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init(){
  forn(i, 0, n){
    mat[i].clear();
    vis[i] = 0;
  }
  forn(i, 0, cnt)ans[i] = cont[i] = 0;
  cnt = 0;
}

void fill(int i, int j, char c){
  cont[cnt]++;
  vis[i][j] = 1;
  forn(k, 0, 4){
    int nxti = i + dy[k];
    int nxtj = j + dx[k];
    if(nxti < 0 || nxti >= n || nxtj < 0 || nxtj >= m)continue;
    if(vis[nxti][nxtj])continue;
    if(mat[nxti][nxtj] != c)continue;
    fill(nxti, nxtj, c);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int caso = 1;

  while(cin >> n >> m){
    if(!n && !m)break;
    cout << "Problem " << caso++ << ":" << endl;
    forn(i, 0, n){
      cin >> mat[i];
    }
    forn(i, 0, n){
      forn(j, 0, m){
        if(vis[i][j])continue;
        if(mat[i][j] == '.'){
          vis[i][j] = 1;
          continue;
        }
        fill(i, j, mat[i][j]);
        ans[cnt] = mat[i][j];
        cnt++;
      }
    }
    vector<pair<int, char>> v;
    forn(i, 0, cnt){
      v.pb({cont[i], -ans[i]});
    }
    sort(v.rbegin(), v.rend());

    for(auto &x: v){
      char c = (x.S*-1);
      cout << c << " " << x.F << endl;
    }

    init();
  }




}