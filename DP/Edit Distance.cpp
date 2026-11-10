#include <bits/stdc++.h>
#define ll long long int
#define en '\n'
using namespace std;

const ll N = 5e3 + 5;
ll dp[N][N];
ll n, m;
string a, b;
ll func(ll i, ll j) {
    if(i == n && j == m) return 0;
    if(i == n) {
        return m - j;
    }
    if(j == m) {
        return n - i;
    }
    ll &ans = dp[i][j];
    if(ans != -1) return ans;
    
    ans = 1e9;
    // remove
    ans = min(ans, func(i + 1, j) + 1LL);
    // replace 
    ans = min(ans, func(i + 1, j + 1) + 1LL);
    // add
    ans = min(ans, func(i, j + 1) + 1LL);
    // match
    if(a[i] == b[j]) ans = min(ans, func(i + 1, j + 1));

    return ans;
}


void solve() {
    cin >> a;
    cin >> b;

    n = a.length();
    m = b.length();

    memset(dp, -1, sizeof(dp));

    ll ans = func(0, 0);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);

    ll t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;   
}
