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

const int N = 105;
int H[N];

int getMax(int a, int b){
  int mx = 0;
  forn(i, a, b){
    mx = max(mx, H[i]);
  }
  return mx;
}

void updt(int a, int b, int val){
  forn(i, a, b)H[i] = val;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m, h, v, l;
  cin >> n >> m;

  forn(i, 0, m){
    cin >> h >> v >> l;
    int r = l+h;
    int mx = getMax(l, r);
    mx += v;
    updt(l, r, mx);
  }

  cout << getMax(0, n+1) << endl;


}