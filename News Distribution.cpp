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

const ll N = 1e6 + 1;
vector<ll> graph[N];
vector<bool> vis(N,0);
ll n,m;

void dfs(ll ver, ll& siz, vector<ll>& curr) {
    vis[ver] = 1;
    if(ver < n) {
        siz++;
        curr.push_back(ver);
    }
    for(auto& child : graph[ver]) {
        if(vis[child]) continue;
        dfs(child,siz,curr);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //whenever we have like groups and we want to make graph pick an number which is out of bound of whole group and make edge between that num and all persons in O(n) otherwise we have to make edges between all then it would be O(n2) 
    cin >> n >> m;
    for(ll i=0; i<m; i++) {
        ll k;
        cin >> k;
        while(k--) {
            ll x;
            cin >> x;
            --x;
            //i+n will be distinct for all groups and also out of bound of all the indices of persons so make edge with it then when traversing the dfs just avoid them which are greater or euqal to n
            graph[x].push_back(i+n);
            graph[i+n].push_back(x);
        }
    }
    vector<ll> ans(n,0);
    for(ll i=0; i<n; i++) {
        if(vis[i]) continue;
        ll siz = 0;
        vector<ll> curr;
        dfs(i,siz,curr);
        for(auto& c : curr) ans[c] = siz;
    }
    for(ll i=0; i<n; i++) cout << ans[i] << " ";
    return 0;
}