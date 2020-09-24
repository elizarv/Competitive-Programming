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

  int t;
  cin >> t;
  while(t--){
      int n;
      cin >> n;
      int cur = n/2;
      bool f = true;
      if(n&1){
          cur++;
          f = false;
      }
      int cnt = 1;
      forn(i, 0, n){
          cout << cur << " \n"[i+1 == n];
          if(!f)cur -= cnt;
          else cur += cnt;
          f = !f;
          cnt ++;
      }
  }
    
  
}

