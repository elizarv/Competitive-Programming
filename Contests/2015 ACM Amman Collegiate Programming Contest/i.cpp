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

  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int n = s.size();
    bool f = true;
    int k = n-1;
    for(; k; k--){
      forn(d, 0, 10){
        f = true;
        int acum = 0;
        vector<int> border(n+1, 0);
        int i = 0;
        for(; i < n-k+1; i++){
          acum -= border[i];
          int cur = s[i]-'0';
          cur = (cur + acum) % 10;
          int dif = 10 - cur + d;
          border[i+k] = dif;
          acum += dif;
        }
        for(; i < n; i++){
          acum -= border[i];
          int cur = s[i]-'0';
          cur = (cur + acum) %10;
          if(cur != d){
            f = false;
          }
        }
        if(f){
          break;
        }
      }
      if(f){
        break;
      }
    }
    cout << k << endl;
  }
  
}
