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

vector<ll> per = {4,8,15,16,23,42};
vector<ll> ans(4,-1);

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(ll i=0; i<4; i++) {
        cout << "? " << i+1 << " " << i+2 << "\n";
        cin >> ans[i];
    }
    //just try out all the permutations that can be possible because at most it will be 6!=720
    do {
        bool good = 1;
        for(ll i=0; i<4; i++) {
            if(per[i]*per[i+1] != ans[i]) {
                good = 0;
                break;
            }
        }
        if(good) break;
    }while(next_permutation(whole(per)));
    cout << "! ";
    for(ll i=0; i<6; i++) {
        cout << per[i] << " ";
    }
    cout << "\n";
    return 0;
}