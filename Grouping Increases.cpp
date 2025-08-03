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
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        ll t1 = INF, t2 = INF;
        //we will keep pushing elements into two sets t1 and t2 now consider we have t1 > t2 so we will swap it because we will always look to make t1 <= t2 then if our current element is smaller than t1 so we will push it into t1 because we still have wider range for t2, then if it is greater than t1 but smaller than t2 then we will push it into t2, then if it is greater than both so we will push it into t1 because we will still have wider range for t2 than t1
        for(ll i=0; i<n; i++) {
            if(t1 > t2) swap(t1,t2);
            ll x = a[i];
            if(x <= t1) t1 = x;
            else if(x <= t2) t2 = x;
            else {t1 = x; ans++;}
        }
        cout << ans << "\n";
    }
    return 0;
}