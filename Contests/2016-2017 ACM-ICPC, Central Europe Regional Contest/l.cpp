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

struct var {
  int a, b, c;

  bool back(const var &x){
    return a != x.a && b != x.b && c != x.c;
  }

  bool operator == (const var &x) const {
    return a == x.a && b == x.b && c == x.c;
  }

};

bool v[5][55];
vector<var> imp;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, x;
  cin >> n;
  forn(i, 0, 3){
    forn(j, 0, n){
      cin >> x;
      if(x)v[i][j] = true;
    }
  }

  forn(i, 0, n){
    imp.pb({v[0][i], v[1][i], v[2][i]});
  }

  forn(i, 0, n){
    forn(j, 0, n){
      if(i == j)continue;
      if(imp[i] == imp[j])cout << "x" << i+1 << " -> x" << j+1 << endl; 
      if(imp[i].back(imp[j]))cout << "!x" << i+1 << " -> x" << j+1 << endl; 
    }
  }
  
}