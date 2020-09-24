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


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int r, g, c, a, b;

  cin >> r >> g >> c >> a >> b;

  int mxr = min(a, r+c);
  int mxg = min(b, g+c);
  if(mxr <= r && mxg <= g){
      cout << r+g+c << endl;
  }else cout << min(mxr, mxg) << endl;
}

