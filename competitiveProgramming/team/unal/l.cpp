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

const int N = 2005, inf = 1e9;
string grid[N];
int dist[N][N];
pair<pii, int> par[N][N];
pii St, E;
int n, m;

char dir[4] = {'D', 'L', 'R', 'U'};
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, -1, 1, 0};


bool valid(int i, int j){
  if(i < 0 || j < 0 || i == n || j == m)return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> m;
  forn(i, 0, n){
    cin >> grid[i];
    forn(j, 0, m){
      char ch = grid[i][j];
      if(ch == 'S')St = {i, j};
      if(ch == 'E')E = {i, j};
      dist[i][j] = inf;
    }
  }

  queue<pii> q;
  q.push(St);
  
  dist[St.F][St.S] = 0;
  while(q.size()){
    int i = q.front().F, j = q.front().S;
    if(E == q.front())break;
    q.pop();
    forn(k, 0, 4){
      int di = i+dy[k];
      int dj = j+dx[k];
      while(valid(di, dj) && grid[di][dj] == 'X'){
        di += dy[k], dj += dx[k];
      }
      if(!valid(di, dj))continue;
      if(dist[di][dj] > dist[i][j]+1){
        dist[di][dj] = dist[i][j]+1;
        par[di][dj] = {{i, j}, k};
        q.push({di, dj});
      }
    }
  }

  if(dist[E.F][E.S] == inf){
    cout << "-1" << endl;
    return 0;
  }
  cout << dist[E.F][E.S] << endl;
  vector<char> ans;
  while(E != St){
    int d = par[E.F][E.S].S;
    ans.pb(dir[d]);
    E = par[E.F][E.S].F;
  }
  reverse(ans.begin(), ans.end());
  for(auto x: ans)cout << x;
  cout << endl;
  

 
}