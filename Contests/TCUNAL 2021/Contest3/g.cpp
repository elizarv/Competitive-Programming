#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
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
    int prev;
    bool ans = false;
    pii ran;
    forn(i, 0, n){
      int x; cin >> x;
      if(i){
        if(abs(x - prev) > 1){          ans = true;
          ran = {i, i+1};
        }
      }
      prev = x;
    }

    if(!ans)cout << "NO" << endl;
    else{
      cout << "YES" << endl;
      cout << ran.F << " " << ran.S << endl;
    }
  }


}