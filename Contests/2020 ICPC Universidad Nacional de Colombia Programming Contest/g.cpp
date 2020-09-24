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

const int M = 1e9+7;

int add(int a, int b){
  if(a+b >= M) return a+b-M;
  return a+b;
}

int mult(int a, int b){
  return (1ll*a*b)%M;
}

int invmod(int a){
  return (M-M/2)%M;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp
  //./main < d.txt

  int n, m, a, b;
  cin >> n >> m;
  int ans = 1;
  forn(i, 1, m+1){
    cin >> a >> b;
    ans = mult(ans, mult(mult(n, n-1), invmod(2)));
    n -= 2;
  };
  while(n){
    ans = mult(ans, n);
    n--;
  }
  cout << ans << endl;


  
}