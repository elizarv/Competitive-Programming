#include <bits/stdc++.h>
using namespace std;
void print() {cout<<endl;}
template<typename T,typename... E>
void print(T t,E... e) {cout<<t<<(sizeof...(e)?" ":"");print(e...);}
#define forn(i,x,n) for(int i=int(x);i<int(n);++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    bool ok = false;
    for (int i = 1; i <= n/i; ++i) {
      if (n%i == 0) {
        int j = n/i;
        if (j <= i*2) ok = true;
      }
    }
    cout << ok << endl;
  }
}