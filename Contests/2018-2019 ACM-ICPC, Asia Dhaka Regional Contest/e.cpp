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
  int aux[] = {8 * 3600 + 30 * 60, 9 * 3600 + 30 * 60, 12 * 3600 + 30 * 60};
  int n;
  while(cin >> n){
    if(!n)break;
    int ans = 0;
    forn(i, 0, n){
      char sft, c;
      int h1, m1, s1, h2, m2, s2;
      cin >> sft >> c >> h1 >> c >> m1 >> c >> s1 >> c >> h2 >> c >> m2 >> c >> s2;
      int t1 = h1 * 60 * 60 + m1 * 60 + s1;
      int t2 = h2 * 60 * 60 + m2 * 60 + s2;
      if (t1 < aux[0]) t1 = aux[0];
      if (sft == 'D') {
        if (t1 > aux[1] || t2 - t1 < 8 * 3600) ans++;
        
      } else if (t1 > aux[2] || t2 - t1 < 9 * 3600) ans++;
    }
    if(!ans){
      cout << "All OK" << endl;
    }else if(ans <= 3){
      cout << ans << " Point(s) Deducted" << endl;
    }else{
      cout << "Issue Show Cause Letter" << endl;
    }
  }
  
}
