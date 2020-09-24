#include <bits/stdc++.h>
using namespace std;


int f(int a, int b, int x, int y){
    int l = x-a;
    int r = y-a;
    int d = y-x;
    if(lb < 0)l = (l+gcd)%gcd, l+=d;
    return min(b-a, r)-l+1;
}

int main(){
    
    int la, ra, lb, rb, ta, tb;
    
    cin >> la >> ra >> ta >> lb >> rb >> tb;

    int gcd = __gcd(ta, tb);

    if(gcd == 1){
        cout << max(ra-la, rb-lb)+1 << endl;
    }

    int ans = 0;

    
    ans = max(ans, f(la, ra, lb, rb);
    ans = max(ans, f(lb, rb, la, ra));

    cout << ans << endl;


}