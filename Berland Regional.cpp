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

map<ll,vector<ll>> uni;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        uni.clear();
        ll n;
        cin >> n;
        vector<ll> u(n), s(n);
        for(ll i=0; i<n; i++) cin >> u[i];
        for(ll i=0; i<n; i++) cin >> s[i];
        for(ll i=0; i<n; i++) {
            if(uni[u[i]].empty()) uni[u[i]].push_back(0);
            uni[u[i]].push_back(s[i]);
        }
        vector<ll> ans(n+1,0);
        for(auto& u : uni) {
            vector<ll>& skills = u.second;
            sort(whole(skills), greater<ll>());
            ll sz = skills.size();
            for(ll i=1; i<sz; i++) skills[i] += skills[i-1];
            for(ll k=1; k<=n; k++) {
                ll ind = ((sz-1)/k)*k;
                if(ind == 0) break;
                ans[k] += skills[ind-1];
            }
        }
        for(ll i=1; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}