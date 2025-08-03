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

bool isPossible(ll l, ll r, vector<vector<ll>>& pfon, ll k) {
    ll ans = 0;
    ll len = (r - l + 1);
    for(ll i=0; i<31; i++) {
        ll curr_on  = -1;
        if(l == 0) curr_on = pfon[i][r];
        else curr_on = pfon[i][r] - pfon[i][l-1];
        if(curr_on == len) ans |=  (1 << i);
    }
    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        vector<vector<ll>> pfon(31, vector<ll>(n,0));
        for(ll i=0; i<31; i++) {
            if((a[0] >> i) & 1) {
                pfon[i][0] = 1;
            }
        }
        for(ll i=0; i<31; i++) {
            for(ll j=1; j<n; j++) {
                if((a[j] >> i) & 1) {
                    pfon[i][j] = pfon[i][j-1] + 1;
                }else {
                    pfon[i][j] = pfon[i][j-1];
                }
            }
        }
        ll q;
        cin >> q;
        while(q--) {
            ll l,k;
            cin >> l >> k;
            l--;
            if(a[l] < k) {
                cout << -1 << " ";
                continue;
            }
            ll lo = l, hi = n-1;
            //tttttttffff
            while((hi - lo) > 1) {
                ll mid = lo + (hi - lo)/2;
                if(isPossible(l,mid,pfon,k)) {
                    lo = mid;
                }else {
                    hi = mid - 1;
                }
            }
            if(isPossible(l,hi,pfon,k)) cout << hi+1 << " ";
            else cout << lo+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}