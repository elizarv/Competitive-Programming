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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int e, a, b, e1 = 0, e2 = 0, tot1 = 0, tot2 = 0;
  forn(i, 0, n){
    cin >> e >> a >> b;
    if(a > b) e1 += e;
    else if(b > a) e2 += e;
    tot1 += a;
    tot2 += b;
  }
  if(tot1 > tot2 && e1 > e2){
    cout << "1" << endl;
  }else if(tot2 > tot1 && e2 > e1){
    cout << "2" << endl;
  }else cout << "0" << endl;
  
}