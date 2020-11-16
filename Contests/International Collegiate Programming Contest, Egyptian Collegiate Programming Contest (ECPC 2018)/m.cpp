#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pii, null_type, greater<pii>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

struct event {
    int type, x, q, id; // type: 1-in 2-qry 3-out

    bool operator < (const event& e) const {
        if (x == e.x) return type < e.type;
        return x < e.x;
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("business.in", "r" , stdin);

  int t, n, m, x, q, r;
  cin >> t;
  
  while(t--){
      cin >> n >> m;
      vector<event> e;
      forn(i, 0, n){
          cin >> x >> q >> r;
					e.pb({1, x, q-x, i});
					e.pb({3, x+r, q-x, i});
      }

			forn(i, 0, m){
				cin >> x >> q;
				e.pb({2, x, q-x, i});
			}

			sort(e.begin(), e.end());

			vector<int> ans(m);

			ordered_set os;

			for (auto &x: e) {
				if (x.type == 1) {
					os.insert({x.q, x.id});
				}else if (x.type == 3) {
					os.erase({x.q, x.id});
				}else{
					ans[x.id] = os.order_of_key({x.q, -1});
				}
			}

			forn(i, 0, m){
				cout << ans[i] << " \n"[i+1 == n];
			}

  }


}