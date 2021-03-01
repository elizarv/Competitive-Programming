//Solution to https://codeforces.com/contest/123/problem/D
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

struct suffixAutomaton {
    struct node {
        int len, link; bool end;
        map<char, int> next;
        bool vis = false;
        ll in, subs;
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

    ll calc(ll cnt){
        return (cnt*(cnt+1))/2;
    }

    ll go(){
        f(0);
        ll r = 0;
        int n = sa.size();
        forn(u, 1, n){
            int par = sa[u].link;
            r += calc(sa[u].subs)*(sa[u].len-sa[par].len);
        }
        return r;
    }

    ll f(int u){
        ll &ans = sa[u].subs;
        if(sa[u].vis)return ans;
        sa[u].vis = true;
        ans = sa[u].end;
        for(auto &ed: sa[u].next){
            int v = ed.S;
            ans += f(v);
        }
        return ans;
    }

};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;
  suffixAutomaton sa(s);
  cout << sa.go() << endl;

  
}