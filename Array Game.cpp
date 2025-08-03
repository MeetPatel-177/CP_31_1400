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
        ll ans = -1;
        if(k >= 3) ans = 0;
        else {
            vector<ll> diffs;
            for(ll i=0; i<n; i++) {
                for(ll j=i+1; j<n; j++) {
                    diffs.push_back(abs(a[i] - a[j]));
                }
            }
            ll poss1 = *min_element(whole(diffs));
            ll poss2 = *min_element(whole(a));
            ans = min(poss1 , poss2);
            if(k == 2) {
                sort(whole(a));
                for(auto& d : diffs) {
                    ll ind = lower_bound(whole(a), d) - a.begin();
                    if(ind == n) continue;
                    ll p1 = abs(a[ind] - d), p2 = INF;
                    if(ind > 0) p2 = abs(a[ind-1] - d);
                    ans = min(ans, min(p1,p2));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}