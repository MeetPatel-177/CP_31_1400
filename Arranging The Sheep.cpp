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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> ind_sheep;
        for(ll i=0; i<n; i++) {
            if(s[i] == '*') ind_sheep.push_back(i);
        }
        ll ans = INF;
        //if there is no sheep
        if(ind_sheep.empty()) ans = 0;
        else {
            ll left_moves = 0, right_moves = 0;
            ll sz = ind_sheep.size();
            //every one gather after 1st sheep
            for(ll i=1; i<sz; i++) {
                right_moves += (ind_sheep[i] - ind_sheep[0]);
                right_moves -= i;
            }
            ans = min(ans, right_moves);
            //now all left will be traversing leftmoves and all right will be traversing rightmoves
            for(ll i=1; i<sz; i++) {
                ll left_sheeps = i;
                left_moves += (left_sheeps*(ind_sheep[i] - ind_sheep[i-1] - 1));
                ll right_sheeps = (sz - i);
                right_moves -= (right_sheeps*(ind_sheep[i] - ind_sheep[i-1] - 1));
                ans = min(ans, left_moves + right_moves);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}