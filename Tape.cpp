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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        //we will keep track of extra gaps that we have between every two broken segments
        vector<ll> gaps;
        for(ll i=1; i<n; i++) {
            gaps.push_back(a[i] - a[i-1] - 1);
        }
        //now we have at most k segments so we can at most cut k-1 times
        //so we will skip the k-1 largest gaps so we will ended up having minimal length
        sort(whole(gaps), greater<ll>());
        ll tot = a[n-1] - a[0] + 1;
        ll i = 0;
        while(i < k-1) {
            tot -= gaps[i];
            ++i;
        }
        cout << tot << "\n";
    } 
    return 0;
}