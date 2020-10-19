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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main l.cpp && ./main < l.txt

  int n;
  cin >> n;
  vector<ll> v(n);
  forn(i, 0, n){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  forn(i, 0, n-2) {
    if (v[i] + v[i+1] > v[i+2]) {
      cout << "possible" << endl;
      return 0;
    }
  }
  cout << "impossible" << endl;
}