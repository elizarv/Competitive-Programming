#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef unsigned long long ull;
typedef pair<int, int> pii;

typedef tree<int, null_type, greater<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
    
typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> order;

const int N = 1e5+5;

int main() {
 ios::sync_with_stdio(0); cin.tie(0);
//  freopen("mtf.in", "r", stdin);
//  freopen("mtf.out", "w", stdout);

	int n, x, prev;
	cin >> n;

	ordered_set os;
	order pos;
	map<int, int> last;
	int cnt = 0;

	forn(i, 0, n){
		cin >> x;
		if(!last.count(x))cout << x+os.order_of_key(x) << " ";
		else{
			cout << pos.size()-pos.order_of_key(last[x]) << " ";
			pos.erase(last[x]);
		}
		last[x] = i;
		prev = x;
		pos.insert(i);
		os.insert(x);
	}
	
	cout << endl;

 }
