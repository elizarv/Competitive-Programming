#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


const int N = 20, M = 60;
int child[N], pack[M];

void init(){
  forn(i, 0, N)child[i] = 0;
  forn(i, 0, M)pack[i] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    init();
    forn(i, 0, n){
      int x;
      cin >> x;
      child[x]++;
    }
    forn(i, 0, m){
      int x;
      cin >> x;
      pack[x]++;
    }

    int candies = 1;
    bool ans = true;
    forn(i, 5, 16){
      if(!child[i])continue;
      while(candies <= 50 && child[i] > pack[candies])candies++;
      if(candies > 50){
        ans = false;
        break;
      }
      candies++;
    }
    
    if(ans)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
}

