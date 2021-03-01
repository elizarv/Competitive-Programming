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

int r, c;
string s;
vector<char> ans;

int getpos(int i, int j){
    return i*c+j;
}

bool valid(int up, int dn, int lf, int rg){
    int pos = up*c+lf;
    int cnt[2] = {0, 0};
    forn(i, up, dn+1){
        forn(j, lf, rg+1){
            int pos = i*c+j;
            int x = s[pos]-'0';
            cnt[x]++;
        }
    }
    if(!cnt[0] || !cnt[1])return true;
    return false;
}

void goB(int up, int dn, int lf, int rg){
    if(up > dn || lf > rg)return;
    if(up == dn && lf == rg){
        ans.pb(s[getpos(up, lf)]);
        return;
    }
    if(!valid(up, dn, lf, rg)){
        int mi = (up+dn)/2;
        int mj = (lf+rg)/2;
        ans.pb('D');
        goB(up, mi, lf, mj);
        goB(up, mi, mj+1, rg);
        goB(mi+1, dn, lf, mj);
        goB(mi+1, dn, mj+1, rg);
    }else{
        ans.pb(s[getpos(up, lf)]);
    }
}


void fill(int up, int dn, int lf, int rg, char val){
    forn(i, up, dn+1){
        forn(j, lf, rg+1){
            int pos = i*c+j;
            ans[pos] = val;
        }
    }
}

int pos;
void goD(int up, int dn, int lf, int rg){
    if(up > dn || lf > rg){
        pos--;
        return;
    }
    if(up == dn && lf == rg){
        ans[getpos(up, lf)] = s[pos];
        return;
    }
    if(s[pos] == 'D'){
        int mi = (up+dn)/2;
        int mj = (lf+rg)/2;
        pos++;
        goD(up, mi, lf, mj);
        pos++;
        goD(up, mi, mj+1, rg);
        pos++;
        goD(mi+1, dn, lf, mj);
        pos++;
        goD(mi+1, dn, mj+1, rg);
    }else{
        fill(up, dn, lf, rg, s[pos]);
    }
}

void readB(){
    s.clear();
    int sz = r*c;
    string t;
    while(sz > 0){
        cin >> t;
        s = s+t;
        sz -= t.size();
    }
}

char ch;

void readD(int up, int dn, int lf, int rg){
    if(up > dn || lf > rg)return;
    if(up == dn && lf == rg){
        cin >> ch;
        s.pb(ch);
        return;
    }
    cin >> ch;
    s.pb(ch);
    if(ch == 'D'){
        int mi = (up+dn)/2;
        int mj = (lf+rg)/2;
        readD(up, mi, lf, mj);
        readD(up, mi, mj+1, rg);
        readD(mi+1, dn, lf, mj);
        readD(mi+1, dn, mj+1, rg);
    }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

    char t;
    while(cin >> t){
        if(t == '#')break;
        cin >> r >> c;
        s.clear();
        ans.clear();
        if(t == 'B'){
            readB();
            goB(0, r-1, 0, c-1);
            cout << "D";
        }else{
            readD(0, r-1, 0, c-1);
            ans.resize(r*c);
            pos = 0;
            goD(0, r-1, 0, c-1);
            cout << "B";
        }
        cout << setw(4) << r << setw(4) << c << endl;
        int cnt = 0;
        for(auto &x: ans){
            if(cnt == 50){
                cout << endl;
                cnt = 0;
            }
            cout << x;
            cnt++;
        }
        cout << endl;
    }
  

}