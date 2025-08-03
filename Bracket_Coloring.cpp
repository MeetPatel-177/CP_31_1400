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
        bool poss = 1;
        ll ff = 0, ss = 0;
        for(ll i=0; i<n; i++) {
            if(s[i] == ')') ss++;
            else ff++;
        }
        if(ff != ss) {
            cout << -1 << "\n";
            continue;
        }
        bool poss_in_1 = 1;
        bool first_ch = (s[0] == '(') ? 0 : 1;
        ff = 0, ss = 0;
        for(ll i=0; i<n; i++) {
            if(s[i] == '(') ff++;
            else ss++;
            if((first_ch == 0 && ss > ff) || (first_ch == 1 && ff > ss)) {
                poss_in_1 = 0;
                break;
            }
        }
        if(poss_in_1) {
            cout << 1 << "\n";
            for(ll i=0; i<n; i++) cout << 1 << " ";
            cout << "\n";
            continue;
        }
        cout << 2 << "\n";
        vector<ll> color(n,2);
        //())(
        stack<ll> stk;
        for(ll i=0; i<n; i++) {
            if(first_ch == 0) {
                if(s[i] == '(') stk.push(i);
                else if(stk.empty()) continue;
                else {
                    ll ind = stk.top();
                    color[i] = color[ind] = 1;
                    stk.pop();
                }
            }else {
                if(s[i] == ')') stk.push(i);
                else if(stk.empty()) continue;
                else {
                    ll ind = stk.top();
                    color[i] = color[ind] = 1;
                    stk.pop();
                }
            }
        }
        for(ll i=0; i<n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}