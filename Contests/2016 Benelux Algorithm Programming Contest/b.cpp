#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T a,Args... args) {cout<<a<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

string s;

bool validate(int i){
  set<char> v;
  forn(j, 0, 3){
    v.insert(s[i]);
    i++;
  }
  return v.size() == 3;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> s;
  int n = s.size();

  map<char, char> counter;
  counter['R'] = 'S';
  counter['B'] = 'K';
  counter['L'] = 'H';

  string ans;

  forn(i, 0, n){
    if((i + 2 < n) && validate(i)){
      ans.pb('C');
      i += 2;
    }else{
      ans.pb(counter[s[i]]);
    }
  }
  cout << ans << endl;

}