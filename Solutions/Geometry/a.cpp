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

typedef double lf;
typedef int T;
struct pt {
  T x, y;
  pt operator + (pt p) { return {x+p.x, y+p.y}; }
  pt operator - (pt p) { return {x-p.x, y-p.y}; }
  pt operator * (pt p) { return {x*p.x-y*p.y, x*p.y+y*p.x}; }
  pt operator * (T d) { return {x*d, y*d}; }
  bool operator == (pt b) { return x == b.x && y == b.y; }
  bool operator != (pt b) { return !(*this == b); }
  bool operator < (const pt &o) const { return y < o.y || (y == o.y && x < o.x); }
  bool operator > (const pt &o) const { return y > o.y || (y == o.y && x > o.x); }
};

T norm(pt a) { return a.x*a.x + a.y*a.y; }
lf abs(pt a) { return sqrt(norm(a)); }
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  pt p[4];
  forn(i, 0, 4){
      cin >> p[i].x >> p[i].y;
  }

  forn(i, 0, 4){
      pt aux = p[i]-p[i+1];
      cout << abs(aux) << " ";
      i++;
  }cout << endl;

  pt aux1 = p[1]-p[0];
  pt aux2 = p[3]-p[2];

  pt sum = aux1 + aux2;
  cout << sum.x << " " << sum.y << endl;

  cout << dot(aux1, aux2) << " " << cross(aux1, aux2) << endl;

  pt tri[3] = {{0, 0}, aux1, aux2};

  ll area = 0;

  forn(i, 0, 3){
      area += cross(tri[i], tri[(i+1)%3]);
  }

  area = abs(area);

  cout << fixed << setprecision(6) << (double)area/2.0 << endl;




  


}