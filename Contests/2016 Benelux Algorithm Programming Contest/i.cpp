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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
    int n;
    cin >> n;
    set<int> fac;
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            fac.insert(i);
            n /= i;
        }
    }
    if(n > 1)fac.insert(n);
    if(fac.size() == 1)cout << "yes" << endl;
    else cout << "no" << endl;


}