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

struct R{
  int l, r, sz;
  bool operator < (const R &b) const {
    if(sz != b.sz)return sz < b.sz;
    return l > b.l;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t, n;
  cin >> t;
  while(t--){
      cin >> n;
      vector<int> v(n, 0);
      priority_queue<R> ranges;
      ranges.push({0, n-1, n});
      int cnt = 1;
      while(ranges.size()){
        auto x = ranges.top();
        ranges.pop();
        int l = x.l;
        int r = x.r;
        int sz = x.sz;
        int mid;
        if(sz&1)mid = (l+r)/2;
        else mid = (l+r-1)/2;
        v[mid] = cnt++;
        int szl = 0, szr = 0;
        if(l < mid)szl = mid-l;
        if(mid < r)szr = r-mid;
        if(szr)ranges.push({mid+1, r, szr});
        if(szl)ranges.push({l, mid-1, szl});
      }
      forn(i, 0, n){
        cout << v[i] << " \n"[i+1 == n];
      }
  }


}



