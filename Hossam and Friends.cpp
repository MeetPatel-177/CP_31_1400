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
        ll n,m;
        cin >> n >> m;
        vector<ll> graph[n+1];
        while(m--) {
            ll v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        ll ans = 0;
        ll prev = -1;
        for(ll i=1; i<=n; i++) {
            //subsegment ends at i
            sort(whole(graph[i]), greater<ll>());
            ll b = i;
            //if every friend of left is friend of each other than a = 1
            ll a = 1;
            for(auto& child : graph[i]) {
                if(child > i) continue;
                else {
                    a = child + 1;
                    break;
                }
            }
            prev = max(a, prev);
            a = prev;
            ll len = (b - a + 1);
            ans += (len);
        }
        cout << ans << "\n";
    }
    return 0;
}