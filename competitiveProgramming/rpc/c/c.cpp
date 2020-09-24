#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

ll r, X, Y, x, y, R;
ll lr, rr, ur, dr;

bool incircle(ll x, ll y){
    return ((x-X)*(x-X) + (y-Y)*(y-Y)) < R*R;
}

bool border(ll x, ll y){
    return ((x-X)*(x-X) + (y-Y)*(y-Y)) == R*R;
}

bool inSquare(ll i, ll j){
    return i > x && i < x+r && j > y && j < y+r;
}

bool borderSq(ll i, ll j){
    if(i > x && i < x+r && j == y)return true;
    if(i > x && i < x+r && j == y+r)return true;
    if(j > y && j < y+r && i == x)return true;
    if(j > y && j < y+r && i == x+r)return true;
    return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> x >> y >> r;

  X = x, Y = y, R = r;
  
  int lc = x-r, rc = x+r, uc = y+r, dc = y-r;

  cin >> x >> y >> r;

  lr = x, rr = x+r, ur = y+r, dr = y;


  if(incircle(x+r, y) || incircle(x+r, y+r) || incircle(x, y) || incircle(x, y+r) || inSquare(X, Y) || inSquare(X+R, Y) || inSquare(X, Y+R) || inSquare(X+R, Y+R)){
      cout << "2" << endl;
      return 0;
  }

  if(border(x, y) || border(x+r, y) || border(x+r, y+r) || border(x, y+r) || borderSq(X+R, Y) || borderSq(X+R, Y+R) || borderSq(X, Y+R) || borderSq(X, Y)){
      cout << "1" << endl;
      return 0;
  }

cout << "0" << endl;

  
}
