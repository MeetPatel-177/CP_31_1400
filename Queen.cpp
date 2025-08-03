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

const ll N = 1e5 + 1;
vector<ll> graph[N];
vector<bool> respect(N,0);
vector<bool> vis(N,0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll root = -1;
        for(ll i=1; i<=n; i++) {
            ll p,c;
            cin >> p >> c;
            respect[i] = c;
            if(p == -1) {
                root = i;
            }
            else {
                graph[i].push_back(p);
                graph[p].push_back(i);
            }
        }
        vector<ll> ans;
        queue<ll> q;
        q.push(root);
        vis[root] = 1;
        while(q.size()) {
            ll ver = q.front(); q.pop();
            bool can_remove = respect[ver];
            for(auto& child : graph[ver]) {
                if(vis[child]) continue;
                vis[child] = 1;
                can_remove &= respect[child];
                q.push(child);
            }
            if(can_remove) ans.push_back(ver);
        }
        sort(whole(ans));
        if(ans.empty()) cout << -1;
        else for(auto& a : ans) cout << a << " ";
    }
    return 0;
}