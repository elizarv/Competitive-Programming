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

/*

1*2 1*3 1*4 [0, 0, 0]
    
2*1 2*3 2*4 [0, 0, 0]

3*1 3*2 3*4 [0, 0, 0]
*/
/*

001
010
011
100
[1, 2, 2]


*/
const int N = 20;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;
  
  bitset<N> v[n];
  int tot[N] = {};
  ll ans = 0;
  
  forn(i, 0, n) {
    int a;
    cin >> a;
    v[i] = a;
    forn(j, 0, N) {
      tot[j] += v[i][j];
    }
  }
  
  
  
  forn(i, 0, n){
      ll sum = 0, acum = 0;
    forn(j, 0, N){
        if(v[i][j])acum = n-tot[j];
        else acum = tot[j];
      sum = acum*(n-tot[j]);
      sum += (n-acum)*tot[j];
      ans += sum << j;
    }
  }
  cout << ans << endl;
}



