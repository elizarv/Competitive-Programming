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

void print(vector<ll>& arr){
    int n = arr.size();
    forn(i, 0, n){
        cout << arr[i] << " \n"[i+1 == n];
    }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int n;
  ll k;
  while(t--){
      cin >> n >> k;
      vector<ll> og(n), a(n), b(n);
      ll mx = 0;
      forn(i, 0, n){
          cin >> og[i];
          mx = max(mx, og[i]);
      }
      ll mx2 = 0;
      forn(i, 0, n){
          a[i] = mx-og[i];
          mx2 = max(mx2, a[i]);
      }
      forn(i, 0, n){
          b[i] = mx2-a[i];
      }
      if(k&1){
          print(a);
      }else print(b);

  }

    
  
}

