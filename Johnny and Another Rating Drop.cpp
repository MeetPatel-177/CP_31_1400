#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"

void binary(ll n) {
    for(ll i=62; i>=0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        //000
        //001
        //010
        //011
        //100
        //101
        //110
        //0111
        //1000
        //1001
        //1010
        //1011
        //1100
        //1101
        //1110
        //1111
        //1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5
        //1 + 2 + 4 + 8 + 16 = (2^(count_bits) - 1)
        ll ans = 0;
        for(ll i=62; i>=0; i--) {
            if((n >> i) & 1) {
                ans += ((1LL << (i+1)) - 1LL);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}