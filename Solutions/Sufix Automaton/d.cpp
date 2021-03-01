//Solution to https://codeforces.com/problemset/problem/452/E
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

const int M = 61, MOD = 1e9+7;
const char L = 'A';

int add(int a, int b){
    if(a + b < MOD)return a+b;
    return a + b - MOD;
}

int subs(int a, int b){
    if(a - b >= 0)return a - b;
    return a - b + MOD;
}

int mul(int a, int b){
    if(1ll * a * b < MOD)return 1ll * a * b;
    return (1ll * a * b) % MOD;
}

struct suffixAutomaton {
    struct node {
        int len, link; bool end;
        map<char, int> next;
        vector<ll> cnt = {0, 0, 0};
        bool vis = false;
        ll in;
    };

    vector<node> sa;
    int last; ll substrs = 0;

    suffixAutomaton() {}
    suffixAutomaton(string &s) {
        sa.reserve(s.size()*2);
        last = add_node();
        sa[0].link = -1;
        sa[0].in = 1;
        for (char &c : s) add_char(c);
        for (int p = last; p; p = sa[p].link) sa[p].end = 1;
    }

    int add_node() { sa.pb({}); return sa.size()-1; }

    void add_char(char c) {
        int u = add_node(), p = last;
        sa[u].len = sa[last].len + 1;
        while (p != -1 && !sa[p].next.count(c)) {
            sa[p].next[c] = u;
            sa[u].in += sa[p].in;
            substrs += sa[p].in;
            p = sa[p].link;
        }
        if (p != -1) {
            int q = sa[p].next[c];
            if (sa[p].len + 1 != sa[q].len) {
                int clone = add_node();
                sa[clone] = sa[q];
                sa[clone].len = sa[p].len + 1;
                sa[clone].in = 0;
                sa[q].link = sa[u].link = clone;
                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    sa[q].in -= sa[p].in;
                    sa[clone].in += sa[p].in;
                    p = sa[p].link;
                }
            } else sa[u].link = q;
        }
        last = u;
    }

    node& operator[](int i) { return sa[i]; }

    bool isend(char c){
        return c >= 'A' && c <= 'D';
    }

    vector<ll> go(){
        int n = sa.size();
        vector<ll> r(n+1, 0);
        forn(i, 1, n){
            vector<ll> aux = f(i);
            int par = sa[i].link;
            int a = sa[par].len;
            int b = sa[i].len;
            int m = 1;
            forn(j, 0, 3){
                m = mul(m, aux[j]);
            }
            r[a+1] = add(r[a+1], m);
            r[b+1] = subs(r[b+1], m);
        }
        forn(i, 0, n){
            r[i+1] = add(r[i+1], r[i]);
        }
        return r;
    }

    vector<ll> f(int u){
        vector<ll> &ans = sa[u].cnt;
        if(sa[u].vis)return ans;
        sa[u].vis = true;
        for(auto &ed: sa[u].next){
            int v = ed.S;
            int c = ed.F;
            if(isend(c)){
                int x = c - 'A';
                ans[x]++;
            }else{
                vector<ll> aux = f(v);
                forn(i, 0, 3){
                    ans[i] += aux[i];
                }
            }
        }
        return ans;
    }

};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    string s = "";
    char end = L;
    int sz = 1e9;
    forn(i, 0, 3){
        string t;
        cin >> t;
        sz = min(sz, (int)t.size());
        s = s + t + end;
        end++;
    }
    suffixAutomaton sa(s);
    vector<ll> ans = sa.go();
    forn(i, 1, sz+1){
        cout << ans[i] << " ";
    }
    cout << endl;
  
}