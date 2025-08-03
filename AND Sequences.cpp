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

const ll N = 2e5 + 1;
ll fact[N];

void pre_compute() {
    fact[0] = 1;
    for(ll i=1; i<N; i++) {
        fact[i] = (fact[i-1] * i) % M;
    }    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_compute();
    ll t = 1;
    cin >> t;
    while(t--) {
        //01011
        //11111
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        sort(whole(a));
        ll mini = a[0];
        ll i = 0;
        while(i < n && a[i] == mini) ++i;
        ll minis = i;
        bool poss = 1;
        while(i < n) {
            for(ll j=0; j<31; j++) {
                if(((mini >> j) & 1) && !((a[i] >> j) & 1)) {
                    poss = 0;
                    break;
                }
            }
            if(!poss) break;
            ++i;
        }
        if(!poss) cout << 0 << "\n";
        else {
            ll ans = 1;
            ans = (minis*(minis-1)) % M;
            ll rem = (n - 2);
            ans = (ans * fact[rem]) % M;
            cout << ans << "\n";
        }
    }
    return 0;
}