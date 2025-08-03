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
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll tot_digs = 0;
        vector<ll> t_zeroes;
        for(ll i=0; i<n; i++) {
            string s = to_string(a[i]);
            tot_digs += s.size();
            ll j = s.size() - 1;
            while(s[j] == '0') j--;
            ll zeroes = (s.size() - j - 1);
            if(zeroes != 0) t_zeroes.push_back(zeroes);
        }
        sort(whole(t_zeroes), greater<ll>());
        ll del_digs = 0;
        ll x = t_zeroes.size();
        for(ll i=0; i<x; i+=2) {
            del_digs += t_zeroes[i];
        }
        ll rem_digs = tot_digs - del_digs;
        if(rem_digs >= (m+1)) cout << "Sasha\n";
        else cout << "Anna\n";
    }
    return 0;
}