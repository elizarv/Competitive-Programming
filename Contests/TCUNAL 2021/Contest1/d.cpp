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

    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        vector<int> cnt(N, 0);
        
        for(auto &ch: t){
            int c = ch - L;
            cnt[c]++;
        }
        
        int ans = 0;
        for(auto &ch: s){
            int c = ch - L;
            if(!cnt[c])break;
            cnt[c]--;
            ans++;
        }
        cout << ans << endl;
    }

}