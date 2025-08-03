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
        ll n, m;
        cin >> n >> m;
        vector<ll> freq(n);
        for(ll i=0; i<m; i++) {
            ll a;
            cin >> a;
            freq[--a]++;
        }
        //lambda function is easy to implement we don't need to pass extra parameters like vectors etc.
        auto check = [&] (ll t) {
            ll can_do = 0;
            for(auto& f : freq) {
                //assign all the 1 hour work first
                ll ff = min(t,f);
                //still he can do this much two hour work
                ll ss = (t - min(t,f))/2;
                //total task any worker can do
                can_do += (ff + ss);
            }
            return (can_do >= m);
        };
        //fffftttttt
        ll lo = 1, hi = 2*m;
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(check(mid)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        if(check(lo)) cout << lo << "\n";
        else cout << hi << "\n";
    }
    return 0;
}