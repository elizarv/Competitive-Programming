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

const int N = 2e5+5, mod = 1e9+7;
int fact[N];

int add(int a, int b){
    if(a + b < mod)return a + b;
    return a + b - mod;
}

int sub(int a, int b){
    if(a - b < 0)return a - b + mod;
    return a - b;
}

int mul(int a, int b){
    if(1ll * a * b < mod)return a * b;
    return (1ll * a * b) % mod;
}

int expmod(int b, int e, int m) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

int invmod(int a, int m) {
    return expmod(a, m-2, m);
}

int ncr(int n, int r){
    int ans = fact[n];
    ans = mul(ans, invmod(fact[r], mod));
    ans = mul(ans, invmod(fact[n-r], mod));
    return ans;
}

void pre(){
    fact[0] = 1;
    forn(i, 1, N){
        fact[i] = mul(fact[i-1], i);
    }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    pre();

    int n;
    cin >> n;
    
    cout << fact[n] << endl;


}