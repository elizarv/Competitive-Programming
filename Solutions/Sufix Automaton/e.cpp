//Solution to https://vjudge.net/problem/SCU-3045
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;++i)
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
        int mask;
        ll in;
        node(){
            len = link = end = in = 0;
            mask = -1;
        }
    };

    vector<node> sa;
    int last; ll substrs;

    suffixAutomaton() {}
    suffixAutomaton(string &s) {
        substrs = 0;
        sa.reserve(s.size()*2);
        last = add_node();
        sa[0].link = -1;
        sa[0].in = 1;
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            add_char(c);
        }
        for (int p = last; p; p = sa[p].link) sa[p].end = 1;
    }

    int add_node() { 
        sa.pb(node()); 
        return sa.size()-1; 
    }

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

    int go(){
        f(0);
        int n = sa.size();
        int ans = 0;
        forn(u, 1, n){
            int aux = f(u);
            if(aux == 3){
                ans = max(ans, sa[u].len);
            }
        }
        return ans;
    }

    int f(int u){
        int &ans = sa[u].mask;
        if(ans != -1)return ans;
        ans = 0;
        map<char, int>::iterator it = sa[u].next.begin();
        for(; it != sa[u].next.end(); it++){
            pair<char, int> ed = *it;
            int v = ed.S;
            int c = ed.F;
            if(isend(c)){
                int x = c - 'A';
                ans |= (1 << x);
            }else{
                ans |= f(v);
            }
        }
        return ans;
    }

};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    string s = "", t;
    while(cin >> s){
        s = s + 'A';
        cin >> t;
        s = s + t + 'B';
        suffixAutomaton sa(s);
        cout << sa.go() << endl;
    }
    return 0;
}