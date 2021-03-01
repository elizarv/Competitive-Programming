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
    int n, a, b, c, k;
    cin >> a >> b >> c >> n >> k;
    int N = a+b+c;
    int num = 0;
    int den = 0;

    forn(mask, 0, (1 << N)){
      int cnt = __builtin_popcount(mask);
      if(cnt != n)continue;
      den++;
      int easy = 0;
      forn(i, 0, a){
        if(mask >> i & 1)easy++;
      }
      if(easy >= k)num++;
    }

    cout << fixed << setprecision(4);
    cout << double(num)/den << endl;

  }
  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/