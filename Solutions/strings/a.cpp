//https://www.urionlinejudge.com.br/judge/en/problems/view/1503
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
typedef unsigned long long ull;
typedef pair<int, int> pii;


int add(int a, int b, int mod){
    if(a+b >= mod)return a+b-mod;
    return a+b;
}

int subs(int a, int b, int mod){
    if(a-b >= 0)return a-b;
    return a-b+mod;
}

int mult(int a, int b, int mod){
    return (1ll*a*b)%mod;
}

const int X[] = {257, 359};
const int M[] = {(ll)1e9+7, (ll)1e9+9};
const int MX = 1e5+10;
int pot[2][MX];

void pre(){
    forn(i, 0, 2){
        pot[i][0] = 1;
        forn(j, 1, MX){
            pot[i][j] = mult(pot[i][j-1], X[i], M[i]);
        }
    }
}

struct Hashing {
    vector<int> h[2];

    Hashing(string &s){
        int n = s.size()+1;
        forn(i, 0, 2){
            h[i] = vector<int>(n, 0);
            forn(j, 1, n){
                h[i][j] = add(mult(h[i][j-1], X[i], M[i]), s[j-1], M[i]);
            }
        }
    }

    ll gethash(int l, int r){
        int ans[2];
        forn(i, 0, 2){
            ans[i] = subs(h[i][r],mult(h[i][l], pot[i][r-l], M[i]), M[i]);
        }
        return ((1ll*ans[0]) << 32) + ans[1];
    }
};

map<pair<ll, int>, int> mapa;

void manacher(string s){
    int n = s.size();
    vector<int> P(n, 0);
    Hashing hs(s);
    map<ll, int> aux;
    int C = 0, R = 0;
    forn(i, 1, n-1){
        int L = C-i+C;
        if(R > i)P[i] = min(R-i, P[L]);
        while(s[i-1-P[i]] == s[i+1+P[i]]){
            P[i]++;
            aux[hs.gethash(i-P[i], i+P[i]+1)] = P[i];
        }
        if(i + P[i] > R){
            C = i;
            R = i+P[i];
        }
    }
    for(auto &x: aux){
        mapa[x]++;
    }
}


int main() {
 ios::sync_with_stdio(0); cin.tie(0);

    pre();

    int n;
    while(cin >> n){ 
        mapa.clear();
        string t;
        forn(i, 0, n){
            cin >> t;
            int m = t.size();
            string s = "%#";
            forn(i, 0, m){
                s += t[i];
                s += "#";
            }
            s += "$";
            manacher(s);
        }
        int ans = 0;
        for(auto &hs: mapa){
            if(hs.S == n)ans = max(ans, hs.F.S);
        }
        cout << ans << endl;
    }

 }
