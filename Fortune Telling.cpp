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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        //both the operation add and xor have same effect on parity of the answer after doing operation
        //11100
        //01101
        //10101 (xor)
        //101001 (sum) 
        //both have unit digit as 1 and it is obvious also
        bool par_x = (x & 1) ? 0 : 1;
        for(ll i=0; i<n; i++) {
            bool par_ai = (a[i] & 1) ? 0 : 1;
            if(par_x == par_ai) par_x = 1;
            else par_x = 0;
        }
        bool par_y = (y & 1) ? 0 : 1;
        //we have given x and x+3 both have different parity so if x is not the answer y will be definately the answer
        if(par_x == par_y) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}