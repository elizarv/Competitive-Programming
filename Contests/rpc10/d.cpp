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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
    string name, file;
    cin >> name >> file;

    int n = file.size();
    string filename;
    if(n > 1 && file.substr(n-2) == ".c")filename = file.substr(0, n-2);
    else if(n > 2 && file.substr(n-3) == ".py")filename = file.substr(0, n-3);
    else if(n > 3 && file.substr(n-4) == ".cpp")filename = file.substr(0, n-4);
    else if(n > 4 && file.substr(n-5) == ".java")filename = file.substr(0, n-5);
    else {
        cout << "Compile Error" << endl;
        return 0;
    }

    if(filename != name){
        cout << "Compile Error" << endl;
        return 0;
    }

    int r, d, e;
    cin >> r >> d >> e; cin.ignore();
    if(r != 0){
        cout << "Run-Time Error" << endl;
        return 0;
    }
    if(e > d){
        cout << "Time Limit Exceeded" << endl;
        return 0;
    }

    int c; cin >> c;cin.ignore();
    vector<string> correct(c);
    forn(i, 0, c){
        getline(cin, correct[i]);
    }
    int t; cin >> t;cin.ignore();
    vector<string> out(t);
    forn(i, 0, t){
        getline(cin, out[i]);
    }

    
    if(correct != out)cout << "Wrong Answer" << endl;
    else cout << "Correct" << endl;

}