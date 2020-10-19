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

const int MAXL = 100;

struct suffixArray {
    string s;
    int n, MX;
    vector<int> ra, tra, sa, tsa, lcp;

    suffixArray(string &_s) {
        s = _s+"$";
        n = s.size();
        MX = max(MAXL, n)+2;
        ra = tra = sa = tsa = lcp = vector<int>(n);
        build();
    }

    void radix_sort(int k) {
        vector<int> cnt(MX, 0);
        for(int i = 0; i < n; i++)
            cnt[(i+k < n) ? ra[i+k]+1 : 1]++;
        for(int i = 1; i < MX; i++)
            cnt[i] += cnt[i-1];
        for(int i = 0; i < n; i++)
            tsa[cnt[(sa[i]+k < n) ? ra[sa[i]+k] : 0]++] = sa[i];
        sa = tsa;
    }

    void build() {
        for (int i = 0; i < n; i++)
            ra[i] = s[i], sa[i] = i;
        for (int k = 1, r; k < n; k <<= 1) {
            radix_sort(k);
            radix_sort(0);
            tra[sa[0]] = r = 0;
            for (int i = 1; i < n; i++) {
                if (ra[sa[i]] != ra[sa[i-1]] || ra[sa[i]+k] != ra[sa[i-1]+k]) ++r;
                tra[sa[i]] = r;
            }
            ra = tra;
            if (ra[sa[n-1]] == n-1) break;
        }
    }

    int& operator[] (int i) { return sa[i]; }
 
};



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  freopen("binary.in", "r", stdin);
  freopen("binary.out", "w", stdout);
  
  int n;
  cin >> n;
  vector<int> sa(n), ra(n);
  forn(i, 0, n){
    cin >> sa[i];
    sa[i]--;
    ra[sa[i]] = i;
  }

  int id = 0, last = n-1, pos;
  while(true){
    pos = ra[last];
    if(pos != id)break;
    id++;
    last--;
  }

  string ans(n, '0');
  forn(i, pos, n){
    ans[sa[i]] = '1';
  }

  suffixArray sufix(ans);

  bool err = false;
  forn(i, 0, n){
    if(sa[i] != sufix[i+1])err = true;
  }

  if(err)cout << "Error";
  else cout << ans;
  cout << endl;



  
  

  
}