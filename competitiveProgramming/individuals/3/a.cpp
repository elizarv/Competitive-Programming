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

  map<char, int> id;
  id['R'] = 0;
  id['P'] = 1;
  id['S'] = 2;

  map<char, char> win;
  win[0] = 'R';
  win[1] = 'P';
  win[2] = 'S';

  string s;
  int t;
  cin >> t;
  while(t--){
      cin >> s;
      int n = s.size();
      vector<int> cnt(3, 0);
      forn(i, 0, n){
          cnt[id[s[i]]]++;
      }
      int mx = 0, pos = 0;
      forn(i, 0, 3){
          if(mx < cnt[i]){
              mx = cnt[i];
              pos = i;
          }
      }
      pos++;
      pos = pos%3;
      forn(i, 0, n)cout << win[pos];
      cout << endl;
  }

  


}



