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
        ll n, m;
        cin >> n >> m;
        //we can make rounded number only by 2,5,10
        ll dup = n;
        ll cnt2 = 0, cnt5 = 0;
        //degree of 2 and 5 in n
        while(n % 2 == 0) {
            cnt2++;
            n >>= 1;
        }
        while(n % 5 == 0) {
            cnt5++;
            n /= 5;
        }
        ll k = 1;
        while(cnt2 < cnt5 && 2*k <= m) {
            k <<= 1;
            cnt2++;
        }
        while(cnt5 < cnt2 && 5*k <= m) {
            k *= 5;
            cnt5++;
        }
        //at last if we have either cnt2==cnt5 in that case we will multiply some 10s by k 
        //in other case we will multiply it by (m/k) as it will be best possible max answer
        while(k*10 <= m) k *= 10;
        k *= (m/k);
        n = dup;
        cout << n*k << "\n";
    }
    return 0;
}