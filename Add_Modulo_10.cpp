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

ll next(ll a) {
    return (a + (a % 10));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        //this is for keep track of any multiples of 5 and 10
        bool flag = 0;
        for(ll i=0; i<n; i++) {
            if(a[i] % 5 == 0) {
                flag = 1;
                a[i] = next(a[i]);
            }
        }
        //if any multiple of 5 encountered then if all are same that is the only possibility 
        if(flag) {
            if((*min_element(whole(a))) == *max_element(whole(a))) yes;
            else no;
        }
        //{2,4,6,8} comes in cycle
        //so make every a[i] % 10 == 2
        //now if we encounter both a[i] % 20 == 2, and a[i] % 20 == 12 then it is not possible to make them equal so only possibility is that every one has same remainder either 2 or 12
        else { 
            bool flag1 = 0, flag2 = 0;
            for(ll i=0; i<n; i++) {
                while(a[i] % 10 != 2) {
                    a[i] = next(a[i]);
                }
                if(a[i] % 20 == 2) flag1 = 1;
                else flag2 = 1;
            }
            if(flag1 && flag2) no;
            else yes;
        } 
    }
    return 0;
}