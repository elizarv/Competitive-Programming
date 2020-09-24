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

typedef long long T;
struct pt{
  T x, y;
  pt operator - (const pt &b) const {
    return {x-b.x, y-b.y};
  }
  pt operator + (const pt &b) const {
    return {x+b.x, y+b.y};
  }
  pt operator * (const pt &p) const {
    return {x*p.x-y*p.y, x*p.y+y*p.x};
  }
  pt operator * (const T d) const {
    return {x*d, y*d};
  }

  bool operator < (const pt &p) const {
    if(x == p.x)return y < p.y;
    return x < p.x;
  }
};

// producto punto
T dot(pt u, pt v){
  return u.x*v.x + u.y*v.y;
}
// producto cruz
T cross(pt u, pt v){
  return u.x*v.y - u.y*v.x;
}

/*
x > 0 izquierda
x < 0 derecha
x = 0 colineales
*/
T orient(pt a, pt b, pt c){
  return cross(b-a, c-a);
}
// si un punto esta en medio
T in_angle(pt a, pt b, pt c){
  pt o = {0,0};
  if(orient(o, a, b) > 0)swap(a, b);
  // a está a la izq de b
  return orient(o, a, c)*orient(o, b, c) < 0; // signos diferentes
}

// area de un poligono
double area(vector<pt> p){
  T ans = 0;
  int n = p.size();
  forn(i, 0, n){
    ans += cross(p[i], p[(i+1)%n]);
  }
  // ans < 0 clockwise
  // ans > 0 counter clockwise
  return abs(ans)/2.0;
}

// true si esta abajo
bool side(pt p){
  return (p.y < 0 || (p.y == 0 && p.x > 0));
}

// comparador según el angulo, con respecto al punto o
pt o = {0, 0};
bool cmp(const pt &a, const pt &b){
  if(side(a-o) == side(b-o))return cross(b-o, a-o) < cross(a-o, b-o);
  return side(a-o) < side(b-o);
}

// Convex Hull
vector<pt> convex_hull(vector<pt> &p){
  int n = p.size();
  vector<pt> ch;
  for(int it = 0; it < 2; it++){
    for(int i = 0; i < n; i++){
      int m = ch.size();
      while(m > 2 && orient(ch[m-1], ch[m-2], p[i]) > 0){
        ch.pop_back();
        m--;
      }
    }
    ch.pop_back();
    reverse(p.begin(), p.end());
  }
  return ch;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x, y;
  cin >> n;
  vector<pt> p;
  forn(i, 0, n){
    cin >> x >> y;
    p.pb({x, y});
  }

  sort(p.begin(), p.end(), cmp);

  
}

