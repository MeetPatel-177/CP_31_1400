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

//we will be able to extend our range from {a-k,b+k} then if this intersection with current pair is null means we can't go through it so return false otherwise take intersection of both the segments as we have to be there 
bool isPossible(ll k, vector<pair<ll,ll>>& a) {
    pair<ll,ll> range = {0,0};
    for(auto& p : a) {
        range = {range.first-k, range.second+k};
        range = {max(range.first,p.first), min(range.second,p.second)};
        if(range.first > range.second) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> a(n);
        for(ll i=0; i<n; i++) cin >> a[i].first >> a[i].second;
        //fffffftttttt
        ll lo = 0, hi = 1e9;
        while((hi - lo) > 1) {
            ll mid = lo + (hi - lo)/2;
            if(isPossible(mid,a)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        // cout << lo << " " << hi << "\n";  
        if(isPossible(lo,a)) {
            cout << lo << "\n";
        }else {
            cout << hi << "\n";
        }
    }
    return 0;
}