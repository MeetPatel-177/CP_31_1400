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
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        //dp(i,1) is we pick 1st from i, dp(i,2) is we pick 2nd from i, dp(i,3) is we don't pick any from i
        //dp(i,1) = max({dp(i-1,2)+a[i], dp(i-1,3)+a[i], a[i]})
        //dp(i,2) = max({dp(i-1,1)+b[i], dp(i-1,3)+b[i], b[i]})
        //dp(i,3) = max(dp(i-1,1), dp(i-1,2))
        ll prev1 = a[0], prev2 = b[0], prev3 = 0;
        for(ll i=1; i<n; i++) {
            ll temp1 = prev1, temp2 = prev2, temp3 = prev3;
            prev1 = max({temp2+a[i], temp3+a[i], a[i]});
            prev2 = max({temp1+b[i], temp3+b[i], b[i]});
            prev3 = max(temp1, temp2);
        }
        ll ans = max({prev1, prev2, prev3});
        cout << ans << "\n";
    }
    return 0;
}