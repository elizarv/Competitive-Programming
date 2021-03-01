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
typedef pair<ll, ll> pll;
typedef double lf;

const int N = 2005;
bitset<2> mat[N][N];
bool corner[N][N];

int dx[2][4] = {{1, 0, -1, 0}, {-1, 0, 1, 0}};
int dy[2][4] = {{0, 1, 0, -1}, {0, -1, 0, 1}};

vector<ll> coor;

int dist(pii a, pii b){
  return abs(coor[a.F] - coor[b.F]) + abs(coor[a.S] - coor[b.S]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, t;
  cin >> n >> t;
  int inix, iniy;
  vector<pair<pii, pii>> line(n);
  forn(i, 0, n){
    pii x, y;
    cin >> x.F >> x.S >> y.F >> y.S;
    if(!i)inix = x.F, iniy = x.S;
    line[i] = {x, y};
    coor.pb(x.F);
    coor.pb(y.F);
    coor.pb(x.S);
    coor.pb(y.S);
  }
  sort(coor.begin(), coor.end());
  coor.resize(distance(coor.begin(), unique(coor.begin(), coor.end())));

  inix = lower_bound(coor.begin(), coor.end(), inix) - coor.begin();
  iniy = lower_bound(coor.begin(), coor.end(), iniy) - coor.begin();
  for(auto &p: line){
    pii &x = p.F;
    pii &y = p.S;
    x.F = lower_bound(coor.begin(), coor.end(), x.F) - coor.begin();
    y.F = lower_bound(coor.begin(), coor.end(), y.F) - coor.begin();
    x.S = lower_bound(coor.begin(), coor.end(), x.S) - coor.begin();
    y.S = lower_bound(coor.begin(), coor.end(), y.S) - coor.begin();
  }

  for(auto &p: line){
    pii &x = p.F;
    pii &y = p.S;
    corner[x.F][x.S] = corner[y.F][y.S] = true;
    if(x.F == y.F){
      int lo = x.S, hi = y.S;
      if(lo > hi) swap(lo, hi);
      forn(i, lo, hi+1){
        mat[x.F][i][0] = 1;
      }
    }else{
      int lo = x.F, hi = y.F;
      if(lo > hi) swap(lo, hi);
      forn(i, lo, hi+1){
        mat[i][x.S][1] = 1;
      }
    }
  }

  vector<pii> pos = {{inix, iniy}};
  vector<ll> d = {0};
  ll sum = 0;

  int x = inix, y = iniy;
  bool dir;
  int move;
  if(mat[x][y] == 1){
    dir = 1;
    if(line[0].F < line[0].S)move = 3;
    else move = 1;
  }else if(mat[x][y] == 2){
    dir = 0;
    if(line[0].F < line[0].S)move = 0;
    else move = 2;
  }

  while(true){
    x += dx[dir][move];
    y += dy[dir][move];
    if(mat[x][y] == 3)move = (move + 1) % 4;
    if(corner[x][y])dir = !dir;
    if(corner[x][y] || mat[x][y] == 3){
      sum += dist(pos[pos.size()-1], {x, y});
      pos.pb({x, y});
      d.pb(sum);
    }
    if(x == inix && y == iniy)break;
  }

  t %= sum;
  
  int l = lower_bound(d.begin(), d.end(), t) - d.begin();
  x = coor[pos[l].F];
  y = coor[pos[l].S];
  int aux = d[l];
  aux -= t;
  if(aux){
    if(pos[l].F == pos[l-1].F){
      if(pos[l].S < pos[l-1].S) y += aux;
      else y -= aux;
    }else{
      if(pos[l].F < pos[l-1].F) x += aux;
      else x -= aux;
    }
  }

  cout << x << " " << y << endl;

}