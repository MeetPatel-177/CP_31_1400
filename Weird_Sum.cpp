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

map<ll,vector<ll>> color_x, color_y;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,m;
    cin >> n >> m;
    //whenever manhattan type problem comes in try to do it individullly for 1d two times
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            ll c;
            cin >> c;
            color_x[c].push_back(i);
            color_y[c].push_back(j);
        }
    }
    ll ans = 0;
    for(auto& it : color_x) {
        vector<ll> v = it.second;
        sort(whole(v));
        ll sz = v.size();
        vector<ll> pf(sz+1);
        for(ll i=0; i<sz; i++) {
            pf[i+1] = (pf[i] + v[i]);
        }
        for(ll i=1; i<=sz; i++) {
            ll per = i-1;
            ll curr = per*v[i-1] - pf[per];
            ans += curr;
        }
    }
    for(auto& it : color_y) {
        vector<ll> v = it.second;
        sort(whole(v));
        ll sz = v.size();
        vector<ll> pf(sz+1);
        for(ll i=0; i<sz; i++) {
            pf[i+1] = (pf[i] + v[i]);
        }
        for(ll i=1; i<=sz; i++) {
            ll per = i-1;
            ll curr = per*v[i-1] - pf[per];
            ans += curr;
        }
    }
    cout << ans << "\n";
    return 0;
}