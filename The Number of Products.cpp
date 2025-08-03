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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        //prev_pos and prev_neg
        ll pos = 0, neg = 0;
        ll prev_pos = 0, prev_neg = 0;
        if(a[0] > 0) {pos++; prev_pos++;}
        else {neg++; prev_neg++;}
        for(ll i=1; i<n; i++) {
            if(a[i] > 0) {
                prev_pos++;
            }else {
                ll temp_pos = prev_pos, temp_neg = prev_neg;
                prev_neg = temp_pos + 1;
                prev_pos = temp_neg;
            }
            pos += prev_pos;
            neg += prev_neg;
        }
        cout << neg << " " << pos << "\n";
    }
    return 0;
}