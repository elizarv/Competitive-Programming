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


bool let(char c){
    if(c >= 'a' && c <= 'z')return true;
    return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    string s;
    getline(cin, s);
    stringstream ss(s);
    string sub;
    vector<string> w;
    string t = "";

    int f = 0;

    while(ss >> sub){
        int i = 0;
        for(auto &x: sub){
            if(f && let(x) && !i){
                w.pb(t);
                t = "";
            }
            t.pb(x);
            if(!let(x)){
                w.pb(t);
                t = "";
            }
            i++;
        }
        f++;
    }
    if(t.size())w.pb(t);
    int n = w.size();
    forn(i, 0, n){
        cout << w[i] << " \n"[i+1 == n];
    }
}