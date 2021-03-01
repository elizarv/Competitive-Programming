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
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

typedef double lf;
const lf eps = 1e-9;
typedef double T;
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  pt operator / (lf d) { return {x/d, y/d}; } /// only for floating point
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

int cmp (lf a, lf b) { return (a + eps < b ? -1 :(b + eps < a ? 1 : 0)); }

T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }

T norm(pt a) { return a.x*a.x + a.y*a.y; }
lf abs(pt a) { return sqrt(norm(a)); }

struct line {
  pt v; T c;
  line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
  T side(pt p) { return cross(v,p)-c; }
  lf dist(pt p) { return abs(side(p)) / abs(v); }
  bool cmp_proj(pt p, pt q) { return dot(v,p) < dot(v,q); }
};

lf pt_to_seg(pt a, pt b, pt p) {
  if(a != b) {
    line l(a,b);
    if (l.cmp_proj(a,p) && l.cmp_proj(p,b)) /// if closest to  projection
      return l.dist(p); /// output distance to line
  }
  return min(abs(p-a), abs(p-b)); /// otherwise distance to A or B
}

const int N = 505, M = 1e5+5;
pair<double, int> R[N][N];
bitset<M> vis;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  forn(i, 0, n){
      int x, y;
      double r;
      cin >> x >> y >> r;
      R[x][y] = {r, i+1};
  }
  int q; cin >> q;
  forn(i, 0, q){
      vis = 0;
      pii a, b;
      cin >> a.F >> a.S >> b.F >> b.S;
      if(a.F > b.F)swap(a, b);
      int lo = max(0, a.F - 1);
      int hi = min(500, b.F + 1);
      pt A = {(T)a.F, (T)a.S}, B = {(T)b.F, (T)b.S};
      if(a.F == b.F){
        if(a.S > b.S)swap(a, b);
        forn(x, lo, hi+1){
          forn(y, a.S, b.S + 1){
            pt p = {(T)x, (T)y};
            if(!R[x][y].S)continue;
            if(cmp(R[x][y].F, pt_to_seg(A, B, p)) > 0)vis[R[x][y].S] = 1;
          }
        }
      }else{
        double m = (double)(b.S-a.S)/(double)(b.F-a.F);
        double aux = a.S - (m * a.F);
        forn(x, lo, hi+1){
          int y1 = (m * (x-1)) + aux;
          int y2 = (m * (x+1)) + aux + 1;
          if(a.S > b.S){
            y1 = (m * (x-1)) + aux + 1;
            y2 = (m * (x+1)) + aux;
          }
          if(y1 > y2)swap(y1, y2);
          y1 = max(y1, 0), y2 = min(y2, 500);
          forn(y, y1, y2+1){
            pt p = {(T)x, (T)y};
            if(!R[x][y].S)continue;
            if(cmp(R[x][y].F, pt_to_seg(A, B, p)) > 0)vis[R[x][y].S] = 1;
          }
        }
      }
      cout << vis.count() << endl;
  }
}
