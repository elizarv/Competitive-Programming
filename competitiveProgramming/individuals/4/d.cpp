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

const int N = 300, inf = 1e9;
int A[N][N];

void init( int n){
  forn(i, 0, n)
    forn(j, 0, n)
      A[i][j] = 0;
}

ll check(int n){
  int mxC = 0, mxR = 0, mnC = inf, mnR = inf;
  vector<int> cols(n, 0);
  forn(i, 0, n){
    int sum = 0;
    forn(j, 0, n){
      sum += A[i][j];
      cols[j] += A[i][j];
    }
    mxR = max(mxR, sum);
    mnR = min(mnR, sum);
    if(i+1 == n){
      mxC = *max_element(cols.begin(), cols.end());
      mnC = *min_element(cols.begin(), cols.end());
    }
  }
  return (mxR-mnR)*(mxR-mnR) + (mxC-mnC)*(mxC-mnC);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    init(n);
    forn(i, 0, n){
      if(!k)break;
      int x = i;
      forn(j, 0, n){
        A[x][j] = 1;
        x = (x+1)%n;
        k--;
        if(!k)break;
      }
    }

    cout << check(n) << endl;

    forn(i, 0, n){
      forn(j, 0, n){
        cout << A[i][j];
      }cout << endl;
    }

  }

    
  
}

