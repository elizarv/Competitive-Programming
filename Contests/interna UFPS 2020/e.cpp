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

int n, puntos, poder;

ll f(int i){
  ll recup = 1ll*i*poder;
  ll per = 1ll*puntos*(n-i);
  return min(recup, per);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    cin >> n >> puntos >> poder;

    int l = 0, r = n+1;
    while(l < r){
      int m = (l+r)/2;
      if(f(m) > f(m+1))r = m;
      else l = m+1;
    }

    cout << l << endl;


  }
  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/