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
        ll n,k;
        cin >> n >> k;
        vector<vector<ll>> dp(k+1, vector<ll>(n+1,0));
        //dp[i][j] is the number of good sequences of length i that ends at j
        //every single element sequence is valid and good that is base case
        for(ll i=1; i<=n; i++) dp[1][i] = 1;
        for(ll i=2; i<=k; i++) {
            for(ll j=1; j<=n; j++) {
                for(ll x=j; x<=n; x+=j) {
                    dp[i][x] = (dp[i][x] + dp[i-1][j]) % M;
                }
            }
        }
        //dp[k][i] for all i from 1 to n will be ans
        ll ans = 0;
        for(ll i=1; i<=n; i++) {
            ans = (ans + dp[k][i]) % M;
        }
        cout << ans << "\n";
    }
    return 0;
}