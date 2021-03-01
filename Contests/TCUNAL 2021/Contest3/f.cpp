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

  int n;
  cin >> n;


  vector<int> v(n);
  int mx = 0;
  forn(i, 0, n){
      cin >> v[i];
      mx = max(mx, v[i]);
  }
  if(n == 1){
      cout << "YES" << endl;
      return 0;
  }

  int i = 1, j = n-2;



  while(i < n && v[i] > v[i-1])i++;
  while(j >= 0 && v[j] > v[j+1])j--;


    bool ans = true;
  forn(x, i, j+1){
      if(v[x] != mx)ans = false;
  }

    if(ans) cout << "YES";
    else cout << "NO";

    cout << endl;



}