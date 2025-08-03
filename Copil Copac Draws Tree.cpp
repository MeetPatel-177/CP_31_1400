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

map<pair<ll,ll>, ll> pos;
void dfs(ll ver, ll par, ll p_par, vector<ll>& dp, vector<ll> graph[]) {
    if(pos[{ver,par}] > pos[{par,p_par}]) {
        dp[ver] = dp[par];
    }else {
        dp[ver] = dp[par] + 1;
    }
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        dfs(child,ver,par,dp,graph);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        pos.clear();
        ll n;
        cin >> n;
        vector<ll> graph[n+1];
        pos[{1,0}] = pos[{0,1}] = 0;
        pos[{0,-1}] = pos[{-1,0}] = 0;
        for(ll i=0; i<n-1; i++) {
            ll v1,v2;
            cin >> v1 >> v2;
            pos[{v1,v2}] = pos[{v2,v1}] = (i+1);
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        vector<ll> dp(n+1,0); //dp[i] is the iteration at which we have drawn the node i
        dp[0] = 0;
        dfs(1,0,-1,dp,graph);
        ll ans = *max_element(whole(dp));
        cout << ans << "\n";
    }
    return 0;
}