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

bool isPossible(ll k, vector<ll>& a, vector<ll>& b) {
    ll n = a.size();
    for(ll i=0; i<n-k; i++) {
        if(a[i] >= b[k+i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        a[n-1] = 1;
        for(ll i=0; i<n-1; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        sort(whole(a));
        sort(whole(b));
        //we want ai < bi so we need to manage ai as small as possible and bi as large as possible so we will delete k smallest from b and k largest from a and we will left with first n-k elements of a and last n-k of b and we will check if the condition ai < bi holds for every i if yes then for any i >= k the answer will be yes
        ll j = 0;
        for(ll i=0; i<n; i++) {
            if(a[j] >= b[i]) j++;
        }
        //fffffftttttttt
        ll lo = 0, hi = n;
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(isPossible(mid, a, b)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        if(isPossible(lo,a,b)) {
            cout << lo << "\n";
        }else {
            cout << hi << "\n";
        }
    }
    return 0;
}