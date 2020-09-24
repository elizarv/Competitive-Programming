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

  int lo, hi, n, x;

cin >> lo >> hi >> n;

forn(i, 0, n){
    cin >> x;
    cout << x << " ";
    int extra = x-1000;
    ll ans = 0;
    if(extra > 0){
        ans += hi*extra;
        x -= extra;
    }
    ans += x*lo;
    cout << ans << endl;
}




  
}
