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

map<ll,ll> pps;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll a,b,k;
        cin >> a >> b >> k;
        ll pairs = k*(k-1)/2;
        vector<ll> boys, girls;
        for(ll i=0; i<k; i++) {
            ll b;
            cin >> b;
            boys.push_back(b);
        }
        for(ll j=0; j<k; j++) {
            ll g;
            cin >> g;
            girls.push_back(g);
        }
        sort(whole(boys)); sort(whole(girls));
        ll extra = 0;
        ll i = 0;
        while(i < k) {
            ll j = i;
            ll curr = boys[i];
            while(i < k && boys[i] == curr) ++i;
            ll len = (i - j);
            extra += (len*(len-1))/2;
        }
        i = 0;
        while(i < k) {
            ll j = i;
            ll curr = girls[i];
            while(i < k && girls[i] == curr) ++i;
            ll len = (i - j);
            extra += (len*(len-1))/2;
        }
        ll ans = pairs - extra;
        cout << ans << "\n";
    }
    return 0;
}