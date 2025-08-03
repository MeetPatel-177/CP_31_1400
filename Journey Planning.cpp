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

map<ll,ll> beauty;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        beauty.clear();
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        //bi+1 - (i+1) = bi - i
        //[2 2 1 2 1 1 1 1]
        //[9 5 -2 5 5 9]
        for(ll i=0; i<n; i++) {
            beauty[a[i] - (i+1)] += a[i];
        }
        ll maxi = 0;
        for(auto& b : beauty) {
            maxi = max(maxi, b.second);
        }
        cout << maxi << "\n";
    }
    return 0;
}