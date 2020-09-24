#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n, s;

  cin >> t;
  while(t--){
      cin >> n >> s;
      vector<int> vec(s);
      ll ans = 0;
      forn(i, 0, s){
          cin >> vec[i];
      }
      forn(i, 1, s){
          int fwd, back;
          int cur = vec[i-1];
          int nxt = vec[i];
          if(nxt == cur){
              ans++;
              continue;
          }
          if(nxt < cur){
              fwd = n-cur-1+nxt;
              back = cur-nxt+1;
          }else {
            fwd = nxt-cur-1;
            back = cur+n-nxt+1;
          }
          ans += min(fwd, back);
      }
      cout << ans << endl;

  }


  
}
