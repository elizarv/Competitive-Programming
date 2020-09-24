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

	ll n, x = 1;
	cin >> n;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			x *= i;
			while(n%i == 0){
				n/=i;
			}
		}
	}
	
	cout << x*n << endl;
    
  
}

