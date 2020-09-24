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

const int MAX =100005;
int S[MAX], n;

int LIS (){
    vector<int>lis(n+1, 1);
    forn(i, 1, n+1){
        for(int j = i+i; j < n+1; j+=i){
            if(S[j] > S[i]){
                if(lis[j] < lis[i]+1){
                    lis[j] = lis[i]+1;
                }
            }
        }
    }
    int mx = 0;
    forn(i, 1, n+1)mx = max(mx, lis[i]);
    return mx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
      cin >> n;
      forn(i, 1, n+1){
          cin >> S[i];
      }
      cout << LIS() << endl;
  }



}



