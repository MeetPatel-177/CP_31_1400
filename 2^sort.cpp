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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        ll i = 0;
        while(i < n-1) {
            ll j = i;
            while(i < n-1 && a[i] < 2*a[i+1]) ++i;
            ll len = (i - j + 1);
            ans += max(0LL, len - k);
            ++i;
        }
        cout << ans << "\n";
    }
    return 0;
}