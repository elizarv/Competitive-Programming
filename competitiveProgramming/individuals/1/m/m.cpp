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

  int n;
  cin >> n;
  vector<int> num(n);
  ll tot = 0;
  forn(i, 0, n){
      cin >> num[i];
        tot += num[i];
  }
  if(tot >= n){
      cout << "NO" << endl;
      return 0;
  }
  
  priority_queue<pii, vector<pii>, greater<pii> >pq;
  queue<int> tokill;

  forn(i, 0, n){
      pq.push({num[i], i+1});
  }

cout << "YES"<< endl;
  while(pq.size()){
      auto x = pq.top();
      pq.pop();
      while(x.F){
          cout << x.S << " " << tokill.front() << endl;
          tokill.pop();
          x.F--;
      }
      tokill.push(x.S);
  }
    
  
}

