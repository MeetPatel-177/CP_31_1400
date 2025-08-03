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
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for(ll i=1; i<=n; i++) cin >> a[i];
        vector<ll> dp(n+1,1); //max len beautiful sequence ends at i
        for(ll i=1; i<=n; i++) {
            for(ll j=2*i; j<=n; j+=i) {
                if(a[i] < a[j]) dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        ll ans = *max_element(whole(dp));
        cout << ans << "\n";
    }
    return 0;
}