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
  if(n == 1){
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  int ans = 0, cur = 1;
  vector<int> pos;
  while(cur < n){
    pos.pb(cur);
    cur += 2;
  }
  pos.pb(n);

  cout << pos.size() << endl;
  forn(i, 0, pos.size()){
    cout << pos[i] << " \n"[i+1 == pos.size()]; 
  }

  
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/