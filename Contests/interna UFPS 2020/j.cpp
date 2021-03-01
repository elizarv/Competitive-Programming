#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) { cout << a << " "; debug(args...);}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct paciente {
  int val, seg;
  string nombre;

  bool operator < (const paciente &x) const {
    if(val == x.val) return seg > x.seg;
    return val > x.val;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  while(cin >> t){
    priority_queue<paciente> p;
    while(t--){
      int tipo, seg;
      cin >> tipo >> seg;
      if(tipo == 1){
        int val;
        string nombre;
        cin >> val >> nombre;
        p.push({val, seg, nombre});
      }else{
        paciente tope = p.top();
        p.pop();
        cout << tope.seg << " " << seg << " " << seg-tope.seg << " " << tope.nombre << endl;
      }
    }
  }
}
