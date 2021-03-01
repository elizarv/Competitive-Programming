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
        int dp[26];
        bool vis = false;
        ll in, subs;
        int path = -1;
        char p = 'z'+1;
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

    int max_path(int u){
        int &ans = sa[u].path;
        if(ans != -1)return ans;
        ans = 0;
        for(auto &ed: sa[u].next){
            int v = ed.S;
            ans = max(ans, max_path(v)+1);
        }
        return ans;
    }


};



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    suffixAutomaton sa(s);
    sa.max_path(0);

    int n = s.size();
    vector<vector<int>> psum(n+1, vector<int>(26, 0));

    forn(i, 1, n+1){
        forn(c, 0, 26){
            psum[i][c] = psum[i-1][c];
        }
        int c = s[i-1] - 'a';
        psum[i][c]++;
    }
    
    ll ans = 0;

    forn(i, 1, sa.sa.size()){
        int par = sa[i].link;
        int l = n - sa[i].path - sa[i].len;
        int r = n - sa[i].path - sa[par].len - 1;
        char last = s[r];
        if(sa[par].next.count(last)) ans++;
        for(char c = 'a'; c <= 'z'; c++){
            int j = c - 'a';
            int cnt = psum[r][j] - psum[l][j];
            if(sa[i].next.count(c))ans += cnt;
        }
    }

    cout << ans << endl;
  
}