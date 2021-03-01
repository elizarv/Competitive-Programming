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

const int N = 27;
const char L = 'a';

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);

    forn(i, 0, n)cin >> v[i];

    int unos = 0, ceros = 0;

    bool flag = true;
    vector<int> ans(n);

    forn(i, 0, n){
        if(!i){
            unos = v[i];
            ceros++;
            ans[i] = 0;
        }else{
            if(unos >  n-i-1){
                flag = false;
                break;
            }else if(ceros + unos == v[i]){
                ceros++;
                ans[i] = 0;
            }else if(ceros + unos == v[i] + 1){
                unos--;
                ans[i] = 1;
            }
        }
    }

    if(!flag)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(auto &x: ans){
            cout << x << " ";
        }
        cout << endl;
    }

}