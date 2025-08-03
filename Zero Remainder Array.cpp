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
        //rem = k - n%k
        vector<ll> rem;
        for(ll i=0; i<n; i++) {
            ll a;
            cin >> a;
            if(a % k == 0) continue;
            rem.push_back((k - a%k));
        }
        sort(whole(rem));
        n = rem.size();
        ll ans = 0;
        ll i = 0;
        while(i < n) {
            ll j = i;
            ll curr = rem[i];
            while(i < n && rem[i] == curr) ++i;
            ll len = (i - j);
            //rem[i-1] + (freq-1)*(k)
            ans = max(ans, rem[i-1] + (len-1)*k);
        }
        if(ans != 0) ++ans;
        cout << ans << "\n";
    }
    return 0;
}