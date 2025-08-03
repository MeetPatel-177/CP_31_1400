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
        vector<ll> freq(n,0);
        for(ll i=0; i<n; i++) {
            ll a;
            cin >> a;
            --a;
            freq[a]++;
        }
        sort(whole(freq), greater<ll>());
        ll last = freq[0];
        ll ans = last;
        ll i = 1;
        while(i < n) {
            last = min(last-1, freq[i]);
            if(last == 0) break;
            ans += last;
            ++i;
        }
        cout << ans << "\n";
    }
    return 0;
}